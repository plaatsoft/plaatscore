/********************************************************************************
** Form generated from reading UI file 'add.ui'
**
** Created: Tue 6. Apr 21:29:37 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_H
#define UI_ADD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Add
{
public:
    QLineEdit *addressEdit;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_6;
    QSpinBox *scoreSpinBox;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;
    QLabel *label;
    QSpinBox *mapSpinBox;
    QSpinBox *levelSpinBox;
    QLabel *label_5;
    QLineEdit *nameEdit;
    QComboBox *applicationComboBox;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *versionEdit;
    QLabel *label_8;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *Add)
    {
        if (Add->objectName().isEmpty())
            Add->setObjectName(QString::fromUtf8("Add"));
        Add->resize(229, 230);
        addressEdit = new QLineEdit(Add);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        addressEdit->setGeometry(QRect(15, 120, 128, 20));
        addressEdit->setMaxLength(15);
        label_2 = new QLabel(Add);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(17, 58, 46, 13));
        label_4 = new QLabel(Add);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(155, 8, 46, 13));
        label_6 = new QLabel(Add);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(155, 104, 46, 13));
        scoreSpinBox = new QSpinBox(Add);
        scoreSpinBox->setObjectName(QString::fromUtf8("scoreSpinBox"));
        scoreSpinBox->setGeometry(QRect(154, 25, 63, 22));
        scoreSpinBox->setMaximum(100000000);
        cancelPushButton = new QPushButton(Add);
        cancelPushButton->setObjectName(QString::fromUtf8("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(27, 199, 75, 23));
        okPushButton = new QPushButton(Add);
        okPushButton->setObjectName(QString::fromUtf8("okPushButton"));
        okPushButton->setGeometry(QRect(120, 199, 76, 23));
        label = new QLabel(Add);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(16, 8, 56, 16));
        mapSpinBox = new QSpinBox(Add);
        mapSpinBox->setObjectName(QString::fromUtf8("mapSpinBox"));
        mapSpinBox->setGeometry(QRect(154, 121, 61, 22));
        levelSpinBox = new QSpinBox(Add);
        levelSpinBox->setObjectName(QString::fromUtf8("levelSpinBox"));
        levelSpinBox->setGeometry(QRect(155, 75, 61, 22));
        label_5 = new QLabel(Add);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(156, 59, 46, 13));
        nameEdit = new QLineEdit(Add);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(16, 75, 127, 20));
        nameEdit->setMaxLength(6);
        applicationComboBox = new QComboBox(Add);
        applicationComboBox->setObjectName(QString::fromUtf8("applicationComboBox"));
        applicationComboBox->setGeometry(QRect(16, 25, 126, 22));
        label_3 = new QLabel(Add);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(17, 104, 64, 16));
        label_7 = new QLabel(Add);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(153, 150, 64, 16));
        versionEdit = new QLineEdit(Add);
        versionEdit->setObjectName(QString::fromUtf8("versionEdit"));
        versionEdit->setGeometry(QRect(155, 166, 59, 20));
        versionEdit->setMaxLength(4);
        label_8 = new QLabel(Add);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(17, 148, 64, 16));
        dateTimeEdit = new QDateTimeEdit(Add);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(15, 165, 128, 22));

        retranslateUi(Add);

        QMetaObject::connectSlotsByName(Add);
    } // setupUi

    void retranslateUi(QWidget *Add)
    {
        Add->setWindowTitle(QApplication::translate("Add", "Form", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Add", "Name", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Add", "Score", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Add", "Map", 0, QApplication::UnicodeUTF8));
        cancelPushButton->setText(QApplication::translate("Add", "Cancel", 0, QApplication::UnicodeUTF8));
        okPushButton->setText(QApplication::translate("Add", "Ok", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Add", "Application", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Add", "Level", 0, QApplication::UnicodeUTF8));
        applicationComboBox->clear();
        applicationComboBox->insertItems(0, QStringList()
         << QApplication::translate("Add", "RedSquare", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Add", "SpaceBubble", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Add", "TowerDefense", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("Add", "Address", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Add", "Version", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Add", "Date", 0, QApplication::UnicodeUTF8));
        dateTimeEdit->setDisplayFormat(QApplication::translate("Add", "dd-MM-yyyy HH:mm:ss", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Add: public Ui_Add {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_H
