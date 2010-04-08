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

#ifndef ADD_H
#define ADD_H

#include <QtGui>

namespace Ui {
    class Add;
}

class Add : public QWidget {
    Q_OBJECT
public:
    Add(QWidget *parent = 0);
    ~Add();

    void setApplication(int applId);
    void setName(QString name);
    void setLevel(int level);
    void setScore(int score);
    void setDate(int date);
    void setVersion(QString version);
    void setMap(int map);
    void setAddress(QString address);

    int getApplication();
    QString getName();
    int getLevel();
    int getScore();
    int getDate();
    QString getVersion();
    int getMap();
    QString getAddress();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Add *ui;
    QWidget *parent1;
    void closeEvent(QCloseEvent *event);

private slots:
    void on_okPushButton_clicked();
    void on_cancelPushButton_clicked();
};

#endif // ADD_H

// ********************************************
// The End
// ********************************************
