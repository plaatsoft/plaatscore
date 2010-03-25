/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created: Thu 25. Mar 22:31:17 2010
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
#include <QtGui/QCheckBox>
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
    QLineEdit *webServiceUrlEdit;
    QLabel *label_2;
    QLineEdit *webServiceKeyEdit;
    QPushButton *cancelButton;
    QPushButton *OkButton;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *LoginNameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *proxyAddressEdit;
    QLineEdit *proxyPortEdit;
    QCheckBox *enabledCheckBox;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(391, 261);
        Settings->setMaximumSize(QSize(391, 16777215));
        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 371, 103));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(13, 16, 105, 16));
        webServiceUrlEdit = new QLineEdit(groupBox);
        webServiceUrlEdit->setObjectName(QString::fromUtf8("webServiceUrlEdit"));
        webServiceUrlEdit->setGeometry(QRect(10, 33, 351, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(12, 57, 148, 16));
        webServiceKeyEdit = new QLineEdit(groupBox);
        webServiceKeyEdit->setObjectName(QString::fromUtf8("webServiceKeyEdit"));
        webServiceKeyEdit->setGeometry(QRect(11, 73, 349, 20));
        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(224, 230, 75, 23));
        OkButton = new QPushButton(Settings);
        OkButton->setObjectName(QString::fromUtf8("OkButton"));
        OkButton->setGeometry(QRect(308, 231, 75, 23));
        groupBox_2 = new QGroupBox(Settings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 117, 371, 105));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(14, 19, 62, 16));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(13, 57, 46, 13));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(202, 18, 124, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(200, 59, 70, 16));
        LoginNameEdit = new QLineEdit(groupBox_2);
        LoginNameEdit->setObjectName(QString::fromUtf8("LoginNameEdit"));
        LoginNameEdit->setGeometry(QRect(12, 34, 169, 20));
        passwordEdit = new QLineEdit(groupBox_2);
        passwordEdit->setObjectName(QString::fromUtf8("passwordEdit"));
        passwordEdit->setGeometry(QRect(12, 72, 168, 20));
        proxyAddressEdit = new QLineEdit(groupBox_2);
        proxyAddressEdit->setObjectName(QString::fromUtf8("proxyAddressEdit"));
        proxyAddressEdit->setGeometry(QRect(199, 35, 158, 20));
        proxyPortEdit = new QLineEdit(groupBox_2);
        proxyPortEdit->setObjectName(QString::fromUtf8("proxyPortEdit"));
        proxyPortEdit->setGeometry(QRect(198, 74, 160, 20));
        enabledCheckBox = new QCheckBox(groupBox_2);
        enabledCheckBox->setObjectName(QString::fromUtf8("enabledCheckBox"));
        enabledCheckBox->setGeometry(QRect(115, 13, 70, 17));
        QWidget::setTabOrder(webServiceUrlEdit, webServiceKeyEdit);
        QWidget::setTabOrder(webServiceKeyEdit, LoginNameEdit);
        QWidget::setTabOrder(LoginNameEdit, passwordEdit);
        QWidget::setTabOrder(passwordEdit, proxyAddressEdit);
        QWidget::setTabOrder(proxyAddressEdit, proxyPortEdit);
        QWidget::setTabOrder(proxyPortEdit, cancelButton);
        QWidget::setTabOrder(cancelButton, OkButton);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Settings", "General", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Settings", "Web Service Url", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Settings", "Web Services key (Optional)", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("Settings", "Cancel", 0, QApplication::UnicodeUTF8));
        OkButton->setText(QApplication::translate("Settings", "Ok", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Settings", "HTTP Proxy settings", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Settings", "Login name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Settings", "Password", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Settings", "Proxy Address", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Settings", "Proxy Port", 0, QApplication::UnicodeUTF8));
        enabledCheckBox->setText(QApplication::translate("Settings", "Enabled", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
