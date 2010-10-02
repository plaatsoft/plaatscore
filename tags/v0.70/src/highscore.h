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
#include "releasenotes.h"
#include "donate.h"
#include "credits.h"
#include "add.h"

#define VERSION  "0.70"

enum
{
    STATE_IDLE=0,
    STATE_VERSION_CHECK=1,
    STATE_REQUEST_DATA=2,
    STATE_RELEASE_NOTES=3
};

enum
{
    APPL_NONE=0,
    APPL_REDSQUARE = 1,
    APPL_SPACEBUBBLE = 2,
    APPL_TOWERDEFENSE = 3
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
    void fetchAdd();

private slots:
    // User action methods
    void on_actionNew_Entry_triggered();
    void on_actionCredits_triggered();
    void on_actionDonate_triggered();
    void on_actionRelease_Notes_triggered();
    void on_actionCheck_for_updates_triggered();
    void on_actionSettings_triggered();
    void remove();
    void copy();
    void on_actionAbout_triggered();
    void on_actionTowerDefense_triggered();
    void on_actionSpaceBubble_triggered();
    void on_actionRedSquare_triggered();
    void on_actionExit_triggered();

    // HTTP related methods
    void fetchData(int applId);
    void fetchRemove(int applId, QString id);
    void fetchVersion();
    void fetchReleaseNotes();
    void replyFinished(QNetworkReply*);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::HighScore *ui;
    QNetworkAccessManager *manager;
    QAction *removeAct;
    QAction *copyAct;
    int stateMachine;
    QString data[20][100];
    int applId;

    // Other child windows
    Settings settings;
    About about;
    ReleaseNotes releaseNotes;
    Donate donate;
    Credits credits;
    Add add;

    // Http relate methods
    void parseData(QString response);
    void parseVersion(QString response);
    void parseReleaseNotes(QString response);
    void setProxy();
    QString convertApplication(int applId);

    // Settings methods
    void readSettings();
    void writeSettings();
    const char * getDate(time_t date);

    void closeEvent(QCloseEvent *event);
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
 *  <b>26-09-2010 Version 0.70 (Next Development release)</b>
 *  - Maintenance release.
 *  - Added Qt 4.7.0 libraries.
 *  - Build with QtCreator v2.0.0
 *
 *  <b>08-04-2010 Version 0.60 </b>
 *  - Added new entry window.
 *  - Added copy row data to new entry window.
 *  - Disable inline table editing.
 *  - Disable main window if subwindow is open.
 *  - Build with QtCreator v1.3.1
 *
 *  <b>30-03-2010 Version 0.50</b>
 *  - Show popup window when internet connect fails.
 *  - Added release notes window.
 *  - Added donate window.
 *  - Added credits window.
 *  - Build with QtCreator v1.3.1
 *
 *  <b>28-03-2010 Version 0.40</b>
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
