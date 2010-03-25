/********************************************************************************
** Form generated from reading UI file 'highscore.ui'
**
** Created: Thu 25. Mar 22:19:27 2010
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
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QPushButton *pushButton;
    QFrame *frame;
    QTableWidget *tableWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuActions;
    QMenu *menuHelp;

    void setupUi(QMainWindow *HighScore)
    {
        if (HighScore->objectName().isEmpty())
            HighScore->setObjectName(QString::fromUtf8("HighScore"));
        HighScore->resize(579, 230);
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
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 180, 131, 23));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 10, 561, 161));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Sunken);
        frame->setLineWidth(2);
        frame->setMidLineWidth(2);
        tableWidget = new QTableWidget(frame);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(3, 3, 555, 155));
        tableWidget->setMinimumSize(QSize(351, 0));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setSortingEnabled(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(0);
        HighScore->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(HighScore);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuActions = new QMenu(menuBar);
        menuActions->setObjectName(QString::fromUtf8("menuActions"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        HighScore->setMenuBar(menuBar);
        QWidget::setTabOrder(tableWidget, pushButton);

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
        pushButton->setText(QApplication::translate("HighScore", "Remove", 0, QApplication::UnicodeUTF8));
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
