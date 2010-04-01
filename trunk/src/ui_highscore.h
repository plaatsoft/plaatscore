/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created: Thu 1. Apr 16:19:24 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHSCORE_H
#define UI_HIGHSCORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighScore
{
public:
    QAction *actionExit;
    QAction *actionPong2;
    QAction *actionBibleQuiz;
    QAction *actionRedSquare;
    QAction *actionSpaceBubble;
    QAction *actionTowerDefense;
    QAction *actionAbout;
    QAction *actionSettings;
    QAction *actionCheck_for_updates;
    QAction *actionRelease_Notes;
    QAction *actionDonate;
    QAction *actionCredits;
    QAction *actionNew_Entry;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuActions;
    QMenu *menuFetch_Data;
    QMenu *menuHelp;

    void setupUi(QMainWindow *HighScore)
    {
        if (HighScore->objectName().isEmpty())
            HighScore->setObjectName(QString::fromUtf8("HighScore"));
        HighScore->resize(355, 197);
        actionExit = new QAction(HighScore);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPong2 = new QAction(HighScore);
        actionPong2->setObjectName(QString::fromUtf8("actionPong2"));
        actionPong2->setCheckable(true);
        actionPong2->setEnabled(false);
        actionBibleQuiz = new QAction(HighScore);
        actionBibleQuiz->setObjectName(QString::fromUtf8("actionBibleQuiz"));
        actionBibleQuiz->setCheckable(true);
        actionBibleQuiz->setEnabled(false);
        actionRedSquare = new QAction(HighScore);
        actionRedSquare->setObjectName(QString::fromUtf8("actionRedSquare"));
        actionRedSquare->setCheckable(true);
        actionSpaceBubble = new QAction(HighScore);
        actionSpaceBubble->setObjectName(QString::fromUtf8("actionSpaceBubble"));
        actionSpaceBubble->setCheckable(true);
        actionTowerDefense = new QAction(HighScore);
        actionTowerDefense->setObjectName(QString::fromUtf8("actionTowerDefense"));
        actionTowerDefense->setCheckable(true);
        actionAbout = new QAction(HighScore);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionSettings = new QAction(HighScore);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionCheck_for_updates = new QAction(HighScore);
        actionCheck_for_updates->setObjectName(QString::fromUtf8("actionCheck_for_updates"));
        actionRelease_Notes = new QAction(HighScore);
        actionRelease_Notes->setObjectName(QString::fromUtf8("actionRelease_Notes"));
        actionDonate = new QAction(HighScore);
        actionDonate->setObjectName(QString::fromUtf8("actionDonate"));
        actionCredits = new QAction(HighScore);
        actionCredits->setObjectName(QString::fromUtf8("actionCredits"));
        actionNew_Entry = new QAction(HighScore);
        actionNew_Entry->setObjectName(QString::fromUtf8("actionNew_Entry"));
        centralWidget = new QWidget(HighScore);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 351, 173));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setMinimumSize(QSize(351, 0));
        tableWidget->setSizeIncrement(QSize(1, 1));
        tableWidget->setBaseSize(QSize(300, 300));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setSortingEnabled(false);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        tableWidget->horizontalHeader()->setDefaultSectionSize(100);
        HighScore->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HighScore);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 355, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuFetch_Data = new QMenu(menuActions);
        menuFetch_Data->setObjectName(QString::fromUtf8("menuFetch_Data"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        HighScore->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuActions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuActions->addAction(menuFetch_Data->menuAction());
        menuActions->addAction(actionNew_Entry);
        menuActions->addSeparator();
        menuActions->addAction(actionSettings);
        menuActions->addSeparator();
        menuFetch_Data->addAction(actionPong2);
        menuFetch_Data->addAction(actionBibleQuiz);
        menuFetch_Data->addAction(actionRedSquare);
        menuFetch_Data->addAction(actionSpaceBubble);
        menuFetch_Data->addAction(actionTowerDefense);
        menuHelp->addAction(actionRelease_Notes);
        menuHelp->addAction(actionDonate);
        menuHelp->addAction(actionCredits);
        menuHelp->addSeparator();
        menuHelp->addAction(actionCheck_for_updates);
        menuHelp->addSeparator();
        menuHelp->addAction(actionAbout);

        retranslateUi(HighScore);

        QMetaObject::connectSlotsByName(HighScore);
    } // setupUi

    void retranslateUi(QMainWindow *HighScore)
    {
        HighScore->setWindowTitle(QApplication::translate("HighScore", "HighScore", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("HighScore", "Exit", 0, QApplication::UnicodeUTF8));
        actionPong2->setText(QApplication::translate("HighScore", "Pong2", 0, QApplication::UnicodeUTF8));
        actionBibleQuiz->setText(QApplication::translate("HighScore", "BibleQuiz", 0, QApplication::UnicodeUTF8));
        actionRedSquare->setText(QApplication::translate("HighScore", "RedSquare", 0, QApplication::UnicodeUTF8));
        actionSpaceBubble->setText(QApplication::translate("HighScore", "SpaceBubble", 0, QApplication::UnicodeUTF8));
        actionTowerDefense->setText(QApplication::translate("HighScore", "TowerDefense", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("HighScore", "About", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("HighScore", "Settings", 0, QApplication::UnicodeUTF8));
        actionCheck_for_updates->setText(QApplication::translate("HighScore", "Check for updates...", 0, QApplication::UnicodeUTF8));
        actionRelease_Notes->setText(QApplication::translate("HighScore", "Release Notes", 0, QApplication::UnicodeUTF8));
        actionDonate->setText(QApplication::translate("HighScore", "Donate", 0, QApplication::UnicodeUTF8));
        actionCredits->setText(QApplication::translate("HighScore", "Credits", 0, QApplication::UnicodeUTF8));
        actionNew_Entry->setText(QApplication::translate("HighScore", "New Entry", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("HighScore", "File", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("HighScore", "Actions", 0, QApplication::UnicodeUTF8));
        menuFetch_Data->setTitle(QApplication::translate("HighScore", "Fetch Entries", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("HighScore", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HighScore: public Ui_HighScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
