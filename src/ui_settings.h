/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Thu 25. Mar 09:14:55 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *keyEdit;
    QLabel *label_2;
    QLineEdit *webServiceUrlEdit;
    QPushButton *cancelButton;
    QPushButton *OkButton;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(400, 152);
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(8, 8, 383, 103));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(14, 11, 105, 16));
        keyEdit = new QLineEdit(groupBox);
        keyEdit->setObjectName(QString::fromUtf8("keyEdit"));
        keyEdit->setGeometry(QRect(13, 27, 356, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(13, 52, 97, 16));
        webServiceUrlEdit = new QLineEdit(groupBox);
        webServiceUrlEdit->setObjectName(QString::fromUtf8("webServiceUrlEdit"));
        webServiceUrlEdit->setGeometry(QRect(13, 71, 356, 20));
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(233, 123, 75, 23));
        OkButton = new QPushButton(Settings);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(315, 122, 75, 23));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Settings", "Edit access key", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Web Services URL", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("Settings", "Ok", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
