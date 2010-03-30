/**
 *  @file
 *  @brief The file contain the credits window
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

#include "credits.h"
#include "ui_credits.h"

Credits::Credits(QWidget *parent) : QWidget(parent), ui(new Ui::Credits)
{
    ui->setupUi(this);

    // Set fix windows form size.
    setMinimumSize(225,212);
    setMaximumSize(225,212);

    setWindowTitle("Credits");
}

Credits::~Credits()
{
    delete ui;
}

void Credits::changeEvent(QEvent *e)
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

void Credits::on_pushButton_clicked()
{
    close();
}
