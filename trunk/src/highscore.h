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

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <time.h>
#include <QtGui>
#include <QMainWindow>
#include <QtNetwork>

#include "settings.h"
#include "about.h"

#define VERSION  "0.40"
enum
{
    STATE_IDLE=0,
    STATE_VERSION_CHECK=1,
    STATE_REQUEST_DATA=2
};

namespace Ui {
    class HighScore;
}

class HighScore : public QMainWindow {
    Q_OBJECT

public:
    HighScore(QWidget *parent = 0);
    ~HighScore();
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const;

private slots:
    void on_actionCheck_for_updates_triggered();
    void on_actionSettings_triggered();
    void remove();
    void on_actionAbout_triggered();
    void on_actionTowerDefense_triggered();
    void on_actionSpaceBubble_triggered();
    void on_actionRedSquare_triggered();
    void on_actionBibleQuiz_triggered();
    void on_actionPong2_triggered();
    void on_actionExit_triggered();
    void fetchData();
    void fetchVersion();
    void replyFinished(QNetworkReply*);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::HighScore *ui;
    QNetworkAccessManager *manager;
    QByteArray applValue;
    QByteArray applAction;
    QByteArray applId;
    Settings settings;
    About about;
    QAction *removeAct;
    int stateMachine;

    void parseXML(QString response);
    void parseVersion(QString response);
    void closeEvent(QCloseEvent *event);
    void readSettings();
    void writeSettings();
    const char * getDate(time_t date);
    void resizeEvent(QResizeEvent *event );
    void contextMenuEvent(QContextMenuEvent *event);
    void disableMenu(bool disable);
};

#endif // HIGHSCORE_H

/**
 * @mainpage PlaatScore Documentation
 * @image html PlaatScore.jpg
 * Welcome to the PlaatScore documentation.
 *
 * @section Introduction
 * PlaatStats is Windows HighScore tool
 *
 * @section Links
 * Website: http://www.plaatsoft.nl
 * Code: http://code.google.com/p/plaatscore
 *
 * @section Credits
 * Documentation: wplaat
 *
 * @section WishList
 *  - Table column sorting.
 *
 * @section ReleaseNotes
 *  <b>28-03-2010 Version 0.40 (Next development release)</b>
 *  - Encrypt / Decrypt entered passwords in windows registry.
 *  - Added improve about window.
 *  - Improve screen layout.
 *  - Add new version detection.
 *  - Disable menu buttons when http request is executed.
 *  - Build with QtCreator v1.3.1
 *
 *  <b>27-03-2010 Version 0.30</b>
 *  - Added support for dynamic xml data.
 *  - Make table resizable.
 *  - Added popup menu.
 *  - Disable column sorting (Did not work good).
 *  - Improve screen layout.
 *  - Build with QtCreator v1.3.1
 *
 *  <b>25-03-2010 Version 0.20</b>
 *  - First release for the windows (Qt) scene.
 *  - Added settings page.
 *  - Added Http Proxy support.
 *  - Cleanup code.
 *  - Build with QtCreator v1.3.1
 *
 *  <b>24-03-2010 Version 0.10</b>
 *  - Start building.
 *  - Created GUI.
 *  - Added basic menu.
 *  - Added basic about box.
 *  - Load / Save window position on start / exit.
 *  - Added application icon.
 *  - Build with QtCreator v1.3.1
 */

