/**
 *  @file
 *  @brief The file contain the add window
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

#include "add.h"
#include "ui_add.h"
#include "highscore.h"

extern
// *******************************
// Constructor & Destructor
// *******************************

Add::Add(QWidget *parent) : QWidget(parent), ui(new Ui::Add)
{
    ui->setupUi(this);

    // Set fix windows form size.
    setMinimumSize(229,230);
    setMaximumSize(229,230);

    setWindowTitle("Add Entry");
}

Add::~Add()
{
    delete ui;
}

void Add::changeEvent(QEvent *e)
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

// *******************************
// User Actions
// *******************************

void Add::on_cancelPushButton_clicked()
{
    close();
}

void Add::on_okPushButton_clicked()
{
    //HighScore::fetchAdd();
    close();
}

// *******************************
// Getter and Setters
// *******************************

void Add::setApplication(QByteArray application)
{
    if (application.contains("redsquare"))
    {
        ui->applicationComboBox->setCurrentIndex(0);
    }

}

void Add::setName(QString name)
{
    ui->nameEdit->setText(name);
}

void Add::setLevel(int level)
{
    ui->levelSpinBox->setValue(level);
}

void Add::setScore(int score)
{
    ui->scoreSpinBox->setValue(score);
}

void Add::setDate(int date)
{
    QDateTime dt = QDateTime::currentDateTime();
    dt.setTime_t(date);
    ui->dateTimeEdit->setDateTime(dt);
}

void Add::setVersion(QString version)
{
    ui->versionEdit->setText(version);
}

void Add::setMap(int map)
{
    ui->mapSpinBox->setValue(map);
}

void Add::setAddress(QString address)
{
    ui->addressEdit->setText(address);
}

QString Add::getApplication(void)
{
    switch (ui->applicationComboBox->currentIndex())
    {
        case 1: return "redsquare";
                break;

        case 2: return "spacebubble";
                break;

        case 3: return "towerdefense";
                break;

        default: return "";
    }
}

QString Add::getName()
{
    return ui->nameEdit->text();
}

int Add::getLevel()
{
    return ui->levelSpinBox->value();
}

int Add::getScore()
{
    return ui->scoreSpinBox->value();
}

int Add::getDate()
{
    return ui->dateTimeEdit->dateTime().toTime_t();
}

QString Add::getVersion()
{
    return ui->versionEdit->text();
}

int Add::getMap()
{
    return ui->mapSpinBox->value();
}

QString Add::getAddress()
{
    return ui->addressEdit->text();
}

// *******************************
// The End
// *******************************
