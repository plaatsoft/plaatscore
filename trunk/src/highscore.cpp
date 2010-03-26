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
#include "ui_highscore.h"

HighScore::HighScore(QWidget *parent) : QMainWindow(parent), ui(new Ui::HighScore)
{
    ui->setupUi(this);

    readSettings();

    manager = new QNetworkAccessManager(this);

    connect( manager,
                SIGNAL(finished(QNetworkReply*)),
                this,
                SLOT(replyFinished(QNetworkReply*)) );

    setWindowTitle("PlaatSoft HighScore v0.2");

    // Set fix windows form size.
    setMinimumSize(614,390);
    setMaximumSize(614,390);
}

void HighScore::updateEditorGeometry(QWidget *editor,
     const QStyleOptionViewItem &option, const QModelIndex &/* index */) const
 {
     ui->tableWidget->setGeometry(option.rect);
 }

HighScore::~HighScore()
{
    delete ui;
}

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

void HighScore::closeEvent(QCloseEvent *event)
{
   // Store current window position
   writeSettings();
}

// ********************************************
// Support methods
// ********************************************

void HighScore::parseXML(QString response)
{
   QString id;
   QString name;
   QString level;
   QString score;
   QString dt;
   QString location;
   QTableWidgetItem *column;
   QTableWidgetItem *item;

   QXmlStreamReader reader(response);

   ui->tableWidget->setColumnCount(7);
   ui->tableWidget->setRowCount(response.count("/>"));

   ui->tableWidget->setColumnWidth(0,25);
   column = new QTableWidgetItem("");
   ui->tableWidget->setHorizontalHeaderItem(0, column);

   ui->tableWidget->setColumnWidth(1,60);
   column = new QTableWidgetItem("Id");
   ui->tableWidget->setHorizontalHeaderItem(1, column);

   ui->tableWidget->setColumnWidth(2,60);
   column = new QTableWidgetItem("Name");
   ui->tableWidget->setHorizontalHeaderItem(2, column);

   ui->tableWidget->setColumnWidth(3,40);
   column = new QTableWidgetItem("Level");
   ui->tableWidget->setHorizontalHeaderItem(3, column);

   ui->tableWidget->setColumnWidth(4,50);
   column = new QTableWidgetItem("Score");
   ui->tableWidget->setHorizontalHeaderItem(4, column);

   ui->tableWidget->setColumnWidth(5,120);
   column = new QTableWidgetItem("Timestamp");
   ui->tableWidget->setHorizontalHeaderItem(5, column);

   ui->tableWidget->setColumnWidth(6,150);
   column = new QTableWidgetItem("Location");
   ui->tableWidget->setHorizontalHeaderItem(6, column);

   int i=0;
   while (!reader.atEnd()) {
      reader.readNext();
      if (reader.isStartElement()) {
          if(reader.name() == "item") {
            bool ok;

            id = reader.attributes().value("id").toString();
            name = reader.attributes().value("name").toString();
            level = reader.attributes().value("level").toString();
            score = reader.attributes().value("score").toString();
            dt = reader.attributes().value("dt").toString();
            location = reader.attributes().value("location").toString();

            QTableWidgetItem* chkBoxItem = new QTableWidgetItem();
            chkBoxItem->setCheckState(Qt::Unchecked);
            ui->tableWidget->setItem(i, 0, chkBoxItem);

            item = new QTableWidgetItem(id);
            ui->tableWidget->setItem(i, 1, item);

            item = new QTableWidgetItem(name);
            ui->tableWidget->setItem(i, 2, item);

            item = new QTableWidgetItem(level);
            ui->tableWidget->setItem(i, 3, item);

            item = new QTableWidgetItem(score);
            ui->tableWidget->setItem(i, 4, item);

            int value = dt.toInt(&ok, 10);
            item = new QTableWidgetItem(getDate(value));
            ui->tableWidget->setItem(i, 5, item);

            item = new QTableWidgetItem(location);
            ui->tableWidget->setItem(i, 6, item);

            i++;
          }
      }
   }

   if (reader.hasError()) {
      qDebug() << "The XML file isn't well-formed: "
          << reader.errorString() << endl << endl << endl;
   }
}

void HighScore::fetch()
{
    QSettings settings("PlaatSoft", "PlaatScore");

    // Proxy support
    bool enabled = settings.value("proxyEnabled",false).toBool();
    QNetworkProxy proxy;
    if (enabled)
    {
        qDebug() << "Proxy enabled";
        bool ok;
        proxy.setUser(settings.value("loginName","").toString());
        proxy.setPassword(settings.value("password","").toString());
        proxy.setPort(settings.value("proxyPort","").toString().toInt(&ok, 10));
        proxy.setHostName(settings.value("proxyAddress","").toString());
        proxy.setType(QNetworkProxy::HttpProxy);
    } else {
        proxy.setType(QNetworkProxy::NoProxy);
    }
    manager->setProxy(proxy);

    QNetworkRequest request;
    request.setUrl(QUrl(settings.value("webServiceUrl","").toString()));
    request.setRawHeader("KEY", settings.value("webServiceKey","").toByteArray());
    request.setRawHeader("APPL", applValue);
    request.setRawHeader("ACTION", applAction);
    request.setRawHeader("ID", applId);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "text/xml");

    manager->get(request);
}

void HighScore::replyFinished(QNetworkReply *reply)
{
    QString sA = QString::number( reply->bytesAvailable());
    QString result = reply->readAll();
    QString item;

    qDebug() << sA << "Bytes received ";

    // Filter out illigal characters.
    result=result.replace("&","");
    result=result.replace(";","");
    int pos = result.indexOf("<highscore>");
    result=result.remove(0, pos);

    qDebug() << result;

    parseXML(result);
}

void HighScore::readSettings()
{
    // Fetch previous window position
    QSettings settings("PlaatSoft", "PlaatScore");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    move(pos);
}

void HighScore::writeSettings()
{
    // Store current window position
    QSettings settings("PlaatSoft", "PlaatScore");
    settings.setValue("pos", pos());
}

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

// ********************************************
// User actions.
// ********************************************

void HighScore::on_actionExit_triggered()
{
   exit(0);
}

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

    fetch();
}

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

    fetch();
}

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

    fetch();
}

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

    fetch();
}

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

    fetch();
}

void HighScore::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About"),
       tr("<b>PlaatSoft HighScore</b><br>"
          "Version 0.2 (Build 25-03-2010)<br>"
          "<br>"
          "Created by <i>wplaat</i><br>"
          "<br>"
          "This tool collects the PlaatSoft game highscore from<br>"
          "internet and let the user modified the data<br><br>"
          "All copyrights reserved (c) "
          "<a href='http://www.plaatsoft.nl'>PlaatSoft</a> 2008-2010"));
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
void HighScore::on_pushButton_pressed()
{
    for ( int i = 0; i < ui->tableWidget->rowCount(); i++ ) {
      if( ui->tableWidget->item(i,0)->checkState() == Qt::Checked ) {

          QString id = ui->tableWidget->item( i, 1 )->text();

          applAction = QByteArray("remove");
          QByteArray tmp(id.toAscii());
          applId = tmp;

          qDebug() << "Remove " << id << "  [" << applId << "]";

          fetch();
      }
    }
}

// ********************************************
// The end
// ********************************************



