/**
 *  @file
 *  @brief The file contain the releasenotes window
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

#include "releasenotes.h"
#include "ui_releasenotes.h"

#include "highscore.h"

extern HighScore *highscore;

// *************************************
// Constructor & Destructor
// *************************************

ReleaseNotes::ReleaseNotes(QWidget *parent) : QWidget(parent), ui(new Ui::ReleaseNotes)
{
    ui->setupUi(this);

    // Set fix windows form size.
    setMinimumSize(356,260);
    setMaximumSize(356,260);

    setWindowTitle("Release Notes");
}

ReleaseNotes::~ReleaseNotes()
{
    delete ui;
}


// *************************************
// other
// *************************************


/**
 * Close event
 */
void ReleaseNotes::closeEvent(QCloseEvent *event)
{
    highscore->setDisabled(false);
}


void ReleaseNotes::changeEvent(QEvent *e)
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

void ReleaseNotes::setText(QString text)
{
    ui->textBrowser->setText(text);
}

// *************************************
// user Actions
// *************************************

void ReleaseNotes::on_pushButton_pressed()
{
    close();
    highscore->setDisabled(false);
}

// *************************************
// The end
// *************************************
