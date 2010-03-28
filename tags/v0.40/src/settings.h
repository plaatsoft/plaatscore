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

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
    class Settings;
}

class Settings : public QWidget {
    Q_OBJECT
public:
    Settings(QWidget *parent = 0);
    ~Settings();

    QString encrypt(QString in);
    QString decrypt(QString in);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Settings *ui;
    void readSettings();
    void writeSettings();
    void updateScreen();
    void paintEvent();

private slots:
    void on_enabledCheckBox_clicked();
    void on_OkButton_pressed();
    void on_cancelButton_pressed();
};

#endif // SETTINGS_H

// ********************************************
// The end
// ********************************************
