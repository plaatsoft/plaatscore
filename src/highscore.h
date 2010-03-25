#ifndef HIGHSCORE_H
#define HIGHSCORE_H

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
#include <QMainWindow>
#include <QtNetwork>

#include "settings.h"

namespace Ui {
    class HighScore;
}

class HighScore : public QMainWindow {
    Q_OBJECT

public:
    HighScore(QWidget *parent = 0);
    ~HighScore();
    void updateEditorGeometry(QWidget *editor,
         const QStyleOptionViewItem &option, const QModelIndex &) const;

private slots:
    void on_actionSettings_triggered();
    void on_pushButton_pressed();
    void on_actionAbout_triggered();
    void on_actionTowerDefense_triggered();
    void on_actionSpaceBubble_triggered();
    void on_actionRedSquare_triggered();
    void on_actionBibleQuiz_triggered();
    void on_actionPong2_triggered();
    void on_actionExit_triggered();
    void fetch();
    void replyFinished(QNetworkReply*);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::HighScore *ui;
    QNetworkAccessManager *manager;
    QString address;
    Settings settings;

    void parseXML(QString response);
    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();
    const char * getDate(time_t date);
};

#endif // HIGHSCORE_H
