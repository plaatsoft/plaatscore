/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created: Sat 27. Mar 13:26:52 2010
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
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuActions;
    QMenu *menuHelp;

    void setupUi(QMainWindow *HighScore)
    {
        if (HighScore->objectName().isEmpty())
            HighScore->setObjectName(QString::fromUtf8("HighScore"));
        HighScore->resize(355, 242);
        actionExit = new QAction(HighScore);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionPong2 = new QAction(HighScore);
        actionPong2->setObjectName(QString::fromUtf8("actionPong2"));
        actionPong2->setCheckable(true);
        actionBibleQuiz = new QAction(HighScore);
        actionBibleQuiz->setObjectName(QString::fromUtf8("actionBibleQuiz"));
        actionBibleQuiz->setCheckable(true);
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
        centralWidget = new QWidget(HighScore);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 351, 218));
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
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        HighScore->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuActions->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExit);
        menuActions->addAction(actionPong2);
        menuActions->addAction(actionBibleQuiz);
        menuActions->addAction(actionRedSquare);
        menuActions->addAction(actionSpaceBubble);
        menuActions->addAction(actionTowerDefense);
        menuActions->addSeparator();
        menuActions->addAction(actionSettings);
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
        menuFile->setTitle(QApplication::translate("HighScore", "File", 0, QApplication::UnicodeUTF8));
        menuActions->setTitle(QApplication::translate("HighScore", "Actions", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("HighScore", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HighScore: public Ui_HighScore {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHSCORE_H
