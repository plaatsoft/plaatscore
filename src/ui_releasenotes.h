/********************************************************************************
** Form generated from reading UI file 'releasenotes.ui'
**
** Created: Tue 6. Apr 20:18:43 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RELEASENOTES_H
#define UI_RELEASENOTES_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReleaseNotes
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QWidget *ReleaseNotes)
    {
        if (ReleaseNotes->objectName().isEmpty())
            ReleaseNotes->setObjectName(QString::fromUtf8("ReleaseNotes"));
        ReleaseNotes->resize(356, 259);
        textBrowser = new QTextBrowser(ReleaseNotes);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(9, 6, 337, 213));
        textBrowser->setMinimumSize(QSize(337, 213));
        QPalette palette;
        QBrush brush(QColor(236, 233, 216, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        textBrowser->setPalette(palette);
        textBrowser->setAutoFillBackground(false);
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Plain);
        pushButton = new QPushButton(ReleaseNotes);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(273, 230, 75, 23));

        retranslateUi(ReleaseNotes);

        QMetaObject::connectSlotsByName(ReleaseNotes);
    } // setupUi

    void retranslateUi(QWidget *ReleaseNotes)
    {
        ReleaseNotes->setWindowTitle(QApplication::translate("ReleaseNotes", "Form", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ReleaseNotes", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ReleaseNotes: public Ui_ReleaseNotes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RELEASENOTES_H
