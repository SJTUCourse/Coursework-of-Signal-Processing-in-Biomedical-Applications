/********************************************************************************
** Form generated from reading UI file 'configuredialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUREDIALOG_H
#define UI_CONFIGUREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfigureDialog
{
public:
    QComboBox *cmbDevice;
    QLabel *lblDevice;
    QPushButton *btnOK;
    QPushButton *btnCancel;
    QGroupBox *groupBox;
    QComboBox *cmbChannelStart;
    QLabel *lblValueRange;
    QLabel *lblChannelCount;
    QLabel *lblChannelStart;
    QComboBox *cmbValueRange;
    QComboBox *cmbChannelCount;
    QGroupBox *groupBox_2;
    QLabel *label;
    QLineEdit *txtPointCount1;
    QLabel *label_2;
    QLineEdit *txtPointCount2;
    QLabel *lblProfilepath;
    QLineEdit *txtProfilePath;
    QPushButton *btnBrowse;
    QLabel *label_3;

    void setupUi(QDialog *ConfigureDialog)
    {
        if (ConfigureDialog->objectName().isEmpty())
            ConfigureDialog->setObjectName(QString::fromUtf8("ConfigureDialog"));
        ConfigureDialog->resize(821, 391);
        ConfigureDialog->setMinimumSize(QSize(455, 213));
        cmbDevice = new QComboBox(ConfigureDialog);
        cmbDevice->setObjectName(QString::fromUtf8("cmbDevice"));
        cmbDevice->setGeometry(QRect(110, 100, 181, 21));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cmbDevice->sizePolicy().hasHeightForWidth());
        cmbDevice->setSizePolicy(sizePolicy);
        cmbDevice->setLayoutDirection(Qt::LeftToRight);
        lblDevice = new QLabel(ConfigureDialog);
        lblDevice->setObjectName(QString::fromUtf8("lblDevice"));
        lblDevice->setGeometry(QRect(40, 100, 61, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblDevice->sizePolicy().hasHeightForWidth());
        lblDevice->setSizePolicy(sizePolicy1);
        btnOK = new QPushButton(ConfigureDialog);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));
        btnOK->setGeometry(QRect(530, 320, 75, 23));
        btnCancel = new QPushButton(ConfigureDialog);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));
        btnCancel->setGeometry(QRect(650, 320, 75, 23));
        btnCancel->setAutoDefault(false);
        groupBox = new QGroupBox(ConfigureDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 150, 341, 191));
        cmbChannelStart = new QComboBox(groupBox);
        cmbChannelStart->setObjectName(QString::fromUtf8("cmbChannelStart"));
        cmbChannelStart->setGeometry(QRect(130, 30, 131, 21));
        sizePolicy.setHeightForWidth(cmbChannelStart->sizePolicy().hasHeightForWidth());
        cmbChannelStart->setSizePolicy(sizePolicy);
        lblValueRange = new QLabel(groupBox);
        lblValueRange->setObjectName(QString::fromUtf8("lblValueRange"));
        lblValueRange->setGeometry(QRect(8, 110, 101, 22));
        sizePolicy1.setHeightForWidth(lblValueRange->sizePolicy().hasHeightForWidth());
        lblValueRange->setSizePolicy(sizePolicy1);
        lblValueRange->setMinimumSize(QSize(91, 22));
        lblChannelCount = new QLabel(groupBox);
        lblChannelCount->setObjectName(QString::fromUtf8("lblChannelCount"));
        lblChannelCount->setGeometry(QRect(8, 70, 111, 22));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lblChannelCount->sizePolicy().hasHeightForWidth());
        lblChannelCount->setSizePolicy(sizePolicy2);
        lblChannelCount->setMinimumSize(QSize(91, 22));
        lblChannelStart = new QLabel(groupBox);
        lblChannelStart->setObjectName(QString::fromUtf8("lblChannelStart"));
        lblChannelStart->setGeometry(QRect(8, 30, 111, 22));
        lblChannelStart->setMinimumSize(QSize(91, 22));
        cmbValueRange = new QComboBox(groupBox);
        cmbValueRange->setObjectName(QString::fromUtf8("cmbValueRange"));
        cmbValueRange->setGeometry(QRect(130, 110, 131, 21));
        sizePolicy.setHeightForWidth(cmbValueRange->sizePolicy().hasHeightForWidth());
        cmbValueRange->setSizePolicy(sizePolicy);
        cmbChannelCount = new QComboBox(groupBox);
        cmbChannelCount->setObjectName(QString::fromUtf8("cmbChannelCount"));
        cmbChannelCount->setGeometry(QRect(130, 70, 131, 21));
        sizePolicy.setHeightForWidth(cmbChannelCount->sizePolicy().hasHeightForWidth());
        cmbChannelCount->setSizePolicy(sizePolicy);
        groupBox_2 = new QGroupBox(ConfigureDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(460, 150, 331, 151));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 161, 16));
        label->setMinimumSize(QSize(131, 16));
        txtPointCount1 = new QLineEdit(groupBox_2);
        txtPointCount1->setObjectName(QString::fromUtf8("txtPointCount1"));
        txtPointCount1->setGeometry(QRect(10, 70, 113, 25));
        txtPointCount1->setMinimumSize(QSize(113, 25));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 321, 31));
        label_2->setWordWrap(false);
        txtPointCount2 = new QLineEdit(groupBox_2);
        txtPointCount2->setObjectName(QString::fromUtf8("txtPointCount2"));
        txtPointCount2->setGeometry(QRect(140, 70, 113, 25));
        txtPointCount2->setMinimumSize(QSize(113, 25));
        lblProfilepath = new QLabel(ConfigureDialog);
        lblProfilepath->setObjectName(QString::fromUtf8("lblProfilepath"));
        lblProfilepath->setGeometry(QRect(460, 100, 71, 20));
        sizePolicy1.setHeightForWidth(lblProfilepath->sizePolicy().hasHeightForWidth());
        lblProfilepath->setSizePolicy(sizePolicy1);
        txtProfilePath = new QLineEdit(ConfigureDialog);
        txtProfilePath->setObjectName(QString::fromUtf8("txtProfilePath"));
        txtProfilePath->setGeometry(QRect(530, 100, 131, 20));
        btnBrowse = new QPushButton(ConfigureDialog);
        btnBrowse->setObjectName(QString::fromUtf8("btnBrowse"));
        btnBrowse->setGeometry(QRect(670, 100, 61, 23));
        label_3 = new QLabel(ConfigureDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(280, 30, 271, 16));
#if QT_CONFIG(shortcut)
        lblDevice->setBuddy(cmbDevice);
        lblValueRange->setBuddy(cmbValueRange);
        lblChannelCount->setBuddy(cmbChannelCount);
        lblChannelStart->setBuddy(cmbChannelStart);
        lblProfilepath->setBuddy(cmbDevice);
#endif // QT_CONFIG(shortcut)
        QWidget::setTabOrder(cmbDevice, cmbChannelStart);
        QWidget::setTabOrder(cmbChannelStart, cmbChannelCount);
        QWidget::setTabOrder(cmbChannelCount, cmbValueRange);
        QWidget::setTabOrder(cmbValueRange, btnOK);
        QWidget::setTabOrder(btnOK, btnCancel);

        retranslateUi(ConfigureDialog);

        QMetaObject::connectSlotsByName(ConfigureDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigureDialog)
    {
        ConfigureDialog->setWindowTitle(QCoreApplication::translate("ConfigureDialog", "Static AO - Configuration", nullptr));
        lblDevice->setText(QCoreApplication::translate("ConfigureDialog", "Device:", nullptr));
        btnOK->setText(QCoreApplication::translate("ConfigureDialog", "OK", nullptr));
        btnCancel->setText(QCoreApplication::translate("ConfigureDialog", "Cancel", nullptr));
        groupBox->setTitle(QCoreApplication::translate("ConfigureDialog", "Static AO settings", nullptr));
        lblValueRange->setText(QCoreApplication::translate("ConfigureDialog", "Value range:", nullptr));
        lblChannelCount->setText(QCoreApplication::translate("ConfigureDialog", "Channel count:", nullptr));
        lblChannelStart->setText(QCoreApplication::translate("ConfigureDialog", "Channel start:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("ConfigureDialog", "Output wave settings", nullptr));
        label->setText(QCoreApplication::translate("ConfigureDialog", "Points for each waveform:", nullptr));
        txtPointCount1->setText(QCoreApplication::translate("ConfigureDialog", "400", nullptr));
        label_2->setText(QCoreApplication::translate("ConfigureDialog", "The data number of AO to form a waveform", nullptr));
        txtPointCount2->setText(QCoreApplication::translate("ConfigureDialog", "400", nullptr));
        lblProfilepath->setText(QCoreApplication::translate("ConfigureDialog", "Profile:", nullptr));
        btnBrowse->setText(QCoreApplication::translate("ConfigureDialog", "Browse", nullptr));
        label_3->setText(QCoreApplication::translate("ConfigureDialog", "Project 2 Sunyu Sun & Wanshan Liu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfigureDialog: public Ui_ConfigureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUREDIALOG_H
