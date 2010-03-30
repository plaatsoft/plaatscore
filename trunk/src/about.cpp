/**
 *  @file
 *  @brief The file contain the about window
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

#include "about.h"
#include "ui_about.h"

#include <QtGui>

// ********************************************
// Constructor & Destructor
// ********************************************

About::About(QWidget *parent) : QWidget(parent), ui(new Ui::About)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    scene->addPixmap(QPixmap(":/images/plaatsoft.png"));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();

    // Set fix windows form size.
    setMinimumSize(525,220);
    setMaximumSize(525,220);

    setWindowTitle("About");
}

About::~About()
{
    delete ui;
}

// ********************************************
// Other
// ********************************************

void About::changeEvent(QEvent *e)
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

// ********************************************
// User Actions
// ********************************************

void About::on_pushButton_pressed()
{
    close();
}

// ********************************************
// The end
// ********************************************
