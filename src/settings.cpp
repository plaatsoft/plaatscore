/**
 *  @file
 *  @brief The file contain the settings window
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

#include <QtGui>

#include "settings.h"
#include "ui_settings.h"

// ************************************
// Constructor & Destructor
// ************************************

/**
 * Constructor
 */
Settings::Settings(QWidget *parent): QWidget(parent), ui(new Ui::Settings)
{
    ui->setupUi(this);

    // Set fix windows form size.
    setMinimumSize(390,260);
    setMaximumSize(390,260);

    readSettings();
    updateScreen();

    setWindowTitle("Settings");


}

/**
 * Destructor
 */
Settings::~Settings()
{
    delete ui;
}

// ************************************
// Logic
// ************************************

/**
 * Encrypt QString (Very easy but unsave approach)
 */
QString Settings::encrypt(QString in) {
  QChar* data = in.data();
  int i=0;
  while (!data[i].isNull()) {
     char tmp =data[i].toAscii();
     tmp+=(i+1);
     data[i]=tmp;
     ++data;
  }
  return in;
}

/**
 * Decrypt QString (Very easy but unsave approach)
 */
QString Settings::decrypt(QString in) {
  QChar* data = in.data();
  int i=0;
  while (!data[i].isNull()) {
     char tmp =data[i].toAscii();
     tmp-=(i+1);
     data[i]=tmp;
     ++data;
  }
  return in;
}


/**
 * Change language event
 */
void Settings::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

/**
 * Read settings from Registry
 */
void Settings::readSettings()
{
    // Fetch configuration
    QSettings settings("PlaatSoft", "PlaatScore");

    ui->webServiceUrlEdit->setText(settings.value("webServiceUrl","http://www.plaatsoft.nl/service/score.php").toString());
    ui->webServiceKeyEdit->setText(decrypt(settings.value("webServiceKey","").toString()));

    ui->LoginNameEdit->setText(settings.value("loginName","").toString());
    ui->passwordEdit->setText( decrypt(settings.value("password","").toString()));
    ui->proxyAddressEdit->setText( settings.value("proxyAddress","").toString());
    ui->proxyPortEdit->setText( settings.value("proxyPort","").toString());
    ui->enabledCheckBox->setChecked(settings.value("proxyEnabled",false).toBool());
}

/**
 * Save settings to Registry
 */
void Settings::writeSettings()
{
    // Store configuration
    QSettings settings("PlaatSoft", "PlaatScore");

    settings.setValue("webServiceUrl", ui->webServiceUrlEdit->text());
    settings.setValue("webServiceKey", encrypt(ui->webServiceKeyEdit->text()));
    settings.setValue("loginName", ui->LoginNameEdit->text());
    settings.setValue("password", encrypt(ui->passwordEdit->text()));
    settings.setValue("proxyAddress", ui->proxyAddressEdit->text());
    settings.setValue("proxyPort", ui->proxyPortEdit->text());
    settings.setValue("proxyEnabled", ui->enabledCheckBox->isChecked());
}

/**
 * Update screen components
 */
void Settings::updateScreen()
{
    if (ui->enabledCheckBox->isChecked())
    {
        ui->LoginNameEdit->setEnabled(true);
        ui->passwordEdit->setEnabled(true);
        ui->proxyAddressEdit->setEnabled(true);
        ui->proxyPortEdit->setEnabled(true);
    }
    else
    {
        ui->LoginNameEdit->setEnabled(false);
        ui->passwordEdit->setEnabled(false);
        ui->proxyAddressEdit->setEnabled(false);
        ui->proxyPortEdit->setEnabled(false);
    }
}

void Settings::paintEvent()
    {
        QPainter paint;
        paint.begin( this );                    // start painting widget
        paint.setPen( Qt::blue );               // set blue pen
        paint.drawText( rect(),                 // draw a text, centered
                                    //   in the widget
                        "The Text" );
        paint.end();                            // painting done

        qDebug() << "paintEvent ";
    }

// ************************************
// Button & Menu events
// ************************************

/**
 * Process cancel button event
 */
void Settings::on_cancelButton_pressed()
{
    readSettings();
    close();
}

/**
 * Process ok button event
 */
void Settings::on_OkButton_pressed()
{
    writeSettings();
    close();
}

/**
 * Process enabled proxy checkbox event
 */
void Settings::on_enabledCheckBox_clicked()
{
    updateScreen();
}

// ********************************************
// The end
// ********************************************
