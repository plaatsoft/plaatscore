/**
 *  @file
 *  @brief The file contain the highscore window
 *  @author wplaat
 *
 *  Copyright (C) 2008-2010 PlaatSoft
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 2.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <time.h>

#include <QtGui>
#include <QtXml>
#include <QtNetwork>

#include "highscore.h"
#include "settings.h"
#include "about.h"
#include "ui_highscore.h"

/**
 * Constructor
 */
HighScore::HighScore(QWidget *parent) : QMainWindow(parent), ui(new Ui::HighScore)
{
    ui->setupUi(this);

    readSettings();

    manager = new QNetworkAccessManager(this);

    connect( manager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(replyFinished(QNetworkReply*)) );

    setWindowTitle(tr("PlaatSoft HighScore " VERSION));

    removeAct = new QAction(tr("Remove"), this);
    connect(removeAct, SIGNAL(triggered()), this, SLOT(remove()));

    fetchVersion();
}

/**
 * Destructor
 */
HighScore::~HighScore()
{
   delete ui;
}

/**
 * ???
 */
void HighScore::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
 {
     ui->tableWidget->setGeometry(option.rect);
 }


/**
 * Change language event
 */
void HighScore::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
 * Close event
 */
void HighScore::closeEvent(QCloseEvent *event)
{
   // Store current window position
   writeSettings();
}

// ********************************************
// Support methods
// ********************************************

/**
 * Parse XML data and fill Qt table
 */
void HighScore::parseXML(QString response)
{
   // Filter out illigal characters.
   response=response.replace("&","");
   response=response.replace(";","");

   // Filter start lines without xml data
   response=response.remove(0, response.indexOf("<highscore>"));

   qDebug() << response;

   QString columnId[20];
   QString columnLabel[20];
   QString data[20][100];
   QTableWidgetItem *item;

   QXmlStreamReader reader(response);

   // Parse XML data
   int columnCount=0;
   int rowCount=0;
   while (!reader.atEnd()) {
      reader.readNext();
      if (reader.isStartElement()) {
          if(reader.name() == "header") {
              columnId[columnCount] = reader.attributes().value("id").toString();
              columnLabel[columnCount] = reader.attributes().value("label").toString();
              columnCount++;
          }
          if(reader.name() == "item") {
            for (int y=0; y<columnCount; y++)
            {
                data[y][rowCount]=reader.attributes().value(columnId[y]).toString();
            }
            rowCount++;
         }
      }
   }

   if (reader.hasError()) {
      qDebug() << "The XML file isn't well-formed: "
          << reader.errorString() << endl << endl << endl;
      return;
   }

   // Set table dimensions
   ui->tableWidget->setColumnCount(columnCount+1);
   ui->tableWidget->setRowCount(rowCount);

   // Build Header
   ui->tableWidget->setColumnWidth(0,25);
   item = new QTableWidgetItem("");
   ui->tableWidget->setHorizontalHeaderItem(0, item);

   for (int x=0; x<columnCount; x++)
   {
       item = new QTableWidgetItem(columnLabel[x]);
       ui->tableWidget->setHorizontalHeaderItem(x+1, item);
   }

   // Build Data
   for (int y=0; y<rowCount; y++)
   {
      item = new QTableWidgetItem();
      item->setCheckState(Qt::Unchecked);
      ui->tableWidget->setItem(y, 0, item);

      for (int x=0; x<columnCount; x++)
      {
         item = new QTableWidgetItem(data[x][y]);
         ui->tableWidget->setItem(y, x+1, item);
      }
   }
   ui->tableWidget->resizeColumnsToContents();
}

/**
 * Parse data for version information
 */
void HighScore::parseVersion(QString response)
{
   qDebug() << response;

   QString text;
   int pos = response.indexOf("Version ");
   QString version = response.mid(pos+8,4).simplified();
   if ((version.size()>0) && (version.compare(VERSION)!=0))
   {
       text="New version ";
       text+=version;
       text+=" of PlaatScore is available!<br>";
       text+="Check out http://www.plaatsoft.nl for more information";

       QMessageBox::information(this, tr("Software update"),text);
   }
}

/**
 * Create http request for xml data.
 */
void HighScore::fetchData()
{
    // Disable all menu items
    disableMenu(true);

    QSettings qSettings("PlaatSoft", "PlaatScore");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        proxy.setUser(qSettings.value("loginName","").toString());
        proxy.setPassword(settings.decrypt(qSettings.value("password","").toString()));
        proxy.setPort(qSettings.value("proxyPort","").toString().toInt(&ok, 10));
        proxy.setHostName(qSettings.value("proxyAddress","").toString());
        proxy.setType(QNetworkProxy::HttpProxy);
    } else {
        proxy.setType(QNetworkProxy::NoProxy);
    }
    manager->setProxy(proxy);

    QNetworkRequest request;
    request.setUrl(QUrl(qSettings.value("webServiceUrl","").toString()));
    QString key = settings.decrypt(qSettings.value("webServiceKey","").toString());
    request.setRawHeader("KEY", key.toAscii());
    request.setRawHeader("APPL", applValue);
    request.setRawHeader("ACTION", applAction);
    request.setRawHeader("ID", applId);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");

    manager->get(request);
    stateMachine=STATE_REQUEST_DATA;
}

/**
 * Create http request for version data.
 */
void HighScore::fetchVersion()
{
    // Disable all menu items
    disableMenu(true);

    QSettings qSettings("PlaatSoft", "PlaatScore");

    // Proxy support
    bool enabled = qSettings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        proxy.setUser(qSettings.value("loginName","").toString());
        proxy.setPassword(settings.decrypt(qSettings.value("password","").toString()));
        proxy.setPort(qSettings.value("proxyPort","").toString().toInt(&ok, 10));
        proxy.setHostName(qSettings.value("proxyAddress","").toString());
        proxy.setType(QNetworkProxy::HttpProxy);
    } else {
        proxy.setType(QNetworkProxy::NoProxy);
    }
    manager->setProxy(proxy);

    QNetworkRequest request;
    request.setUrl(QUrl("http://www.plaatsoft.nl/service/plaatscore.html"));

    manager->get(request);
    stateMachine=STATE_VERSION_CHECK;
}

/**
 * Process incoming http response
 */
void HighScore::replyFinished(QNetworkReply *reply)
{
    QString bytesCount = QString::number( reply->bytesAvailable());
    QString result = reply->readAll();

    qDebug() << bytesCount << "Bytes received ";

    switch (stateMachine)
    {
        case STATE_REQUEST_DATA:
        {
            // Parse XML date
            parseXML(result);
            stateMachine=STATE_IDLE;
        }
        break;

        case STATE_VERSION_CHECK:
        {
            parseVersion(result);
            stateMachine=STATE_IDLE;
        }
        break;
    }

    // Enable all menu items
    disableMenu(false);
}

/**
 * Read setting form registry
 */
void HighScore::readSettings()
{
    // Fetch previous window position
    QSettings settings("PlaatSoft", "PlaatScore");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(640, 480)).toSize();
    resize(size);
    move(pos);
}

/**
 * Write settings to registry
 */
void HighScore::writeSettings()
{
    // Store current window position
    QSettings settings("PlaatSoft", "PlaatScore");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
}

/**
 * Convert date to String
 */
const char * HighScore::getDate(time_t date)
{
  struct tm *now = NULL;
  static char buf[ 50 ] ;

  /* Get time and date structure */
  now = localtime(&date);

  // Create time stamp
  sprintf(buf,"%02d-%02d-%04d %02d:%02d:%02d",
        now->tm_mday, now->tm_mon+1, now->tm_year+1900,
        now->tm_hour,now->tm_min,now->tm_sec);

  return buf;
}

/**
 * Resize table if windows is resized
 */
void HighScore::resizeEvent(QResizeEvent *event )
{
    int height = event->size().height();
    int width = event->size().width();

    ui->tableWidget->resize(width,height-20);
}

/**
 * Create popup menu
 */
void HighScore::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(removeAct);
    menu.exec(event->globalPos());
}


/**
 * Disable / enable all fetch menu items
 */
void HighScore::disableMenu(bool disable)
{
  ui->actionPong2->setDisabled(disable);
  ui->actionBibleQuiz->setDisabled(disable);
  ui->actionRedSquare->setDisabled(disable);
  ui->actionSpaceBubble->setDisabled(disable);
  ui->actionTowerDefense->setDisabled(disable);
  ui->actionCheck_for_updates->setDisabled(disable);
}

// ********************************************
// User actions.
// ********************************************

/**
 * Exit menu event
 */
void HighScore::on_actionExit_triggered()
{
   exit(0);
}

/**
 * Pong2 menu event
 */
void HighScore::on_actionPong2_triggered()
{
    // Request HTTP Parameters
    applValue = QByteArray("pong2");
    applAction= QByteArray("");
    applId = QByteArray("");

    ui->actionPong2->setCheckable(true);
    ui->actionBibleQuiz->setChecked(false);
    ui->actionRedSquare->setChecked(false);
    ui->actionSpaceBubble->setChecked(false);
    ui->actionTowerDefense->setChecked(false);

    ui->tableWidget->setRowCount(0);

    fetchData();
}

/**
 * bibleQuiz menu event
 */
void HighScore::on_actionBibleQuiz_triggered()
{
    // Request HTTP Parameters
    applValue = QByteArray("biblequiz");
    applAction= QByteArray("");
    applId = QByteArray("");

    ui->actionPong2->setCheckable(false);
    ui->actionBibleQuiz->setChecked(true);
    ui->actionRedSquare->setChecked(false);
    ui->actionSpaceBubble->setChecked(false);
    ui->actionTowerDefense->setChecked(false);

    ui->tableWidget->setRowCount(0);

    fetchData();
}

/**
 * RedSquare menu event
 */
void HighScore::on_actionRedSquare_triggered()
{
    // Request HTTP Parameters
    applValue = QByteArray("redsquare");
    applAction= QByteArray("");
    applId = QByteArray("");

    ui->actionPong2->setCheckable(false);
    ui->actionBibleQuiz->setChecked(false);
    ui->actionRedSquare->setChecked(true);
    ui->actionSpaceBubble->setChecked(false);
    ui->actionTowerDefense->setChecked(false);

    ui->tableWidget->setRowCount(0);

    fetchData();
}

/**
 * Space Bubble menu event
 */
void HighScore::on_actionSpaceBubble_triggered()
{
    // Request HTTP Parameters
    applValue = QByteArray("spacebubble");
    applAction= QByteArray("");
    applId = QByteArray("");

    ui->actionPong2->setCheckable(false);
    ui->actionBibleQuiz->setChecked(false);
    ui->actionRedSquare->setChecked(false);
    ui->actionSpaceBubble->setChecked(true);
    ui->actionTowerDefense->setChecked(false);

    ui->tableWidget->setRowCount(0);

    fetchData();
}

/**
 * TowerDefense menu event
 */
void HighScore::on_actionTowerDefense_triggered()
{
    // Request HTTP Parameters
    applValue = QByteArray("towerdefense");
    applAction= QByteArray("");
    applId = QByteArray("");

    ui->actionPong2->setCheckable(false);
    ui->actionBibleQuiz->setChecked(false);
    ui->actionRedSquare->setChecked(false);
    ui->actionSpaceBubble->setChecked(false);
    ui->actionTowerDefense->setChecked(true);

    ui->tableWidget->setRowCount(0);

    fetchData();
}

/**
 * About menu event
 */
void HighScore::on_actionAbout_triggered()
{
    // Set settings window position related to Main window.
    QPoint position = QPoint(pos());
    position.setX(position.x()+120);
    position.setY(position.y()+70);
    about.move(position);

    // Make about window visible
    about.show();
}

/**
 * Process open setting window action
 */
void HighScore::on_actionSettings_triggered()
{
    // Set settings window position related to Main window.
    QPoint position = QPoint(pos());
    position.setX(position.x()+120);
    position.setY(position.y()+70);
    settings.move(position);

    // Make settings window visible
    settings.show();
}

/**
 * Process remove button action
 */
void HighScore::remove()
{
    for ( int i = 0; i < ui->tableWidget->rowCount(); i++ ) {
      if( ui->tableWidget->item(i,0)->checkState() == Qt::Checked ) {

          QString id = ui->tableWidget->item( i, 1 )->text();

          applAction = QByteArray("remove");
          QByteArray tmp(id.toAscii());
          applId = tmp;

          qDebug() << "Remove " << id << "  [" << applId << "]";

          fetchData();
      }
    }
}

void HighScore::on_actionCheck_for_updates_triggered()
{
   stateMachine=STATE_VERSION_CHECK;
   fetchVersion();
}


// ********************************************
// The end
// ********************************************





