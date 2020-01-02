/********************************************************************************
** Form generated from reading UI file 'staticdo.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATICDO_H
#define UI_STATICDO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StaticDOClass
{
public:
    QFrame *background;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *btnConfig;
    QLabel *label;
    QPushButton *btnStop;
    QPushButton *btnPause;
    QPushButton *btnStart;
    QLabel *timerFreqLabel;
    QSlider *timerTrackBar;
    QComboBox *FFTChoose;
    QLineEdit *txtPointCount;
    QPushButton *btnStart2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *StaticDOClass)
    {
        if (StaticDOClass->objectName().isEmpty())
            StaticDOClass->setObjectName(QString::fromUtf8("StaticDOClass"));
        StaticDOClass->resize(825, 432);
        StaticDOClass->setMinimumSize(QSize(470, 432));
        background = new QFrame(StaticDOClass);
        background->setObjectName(QString::fromUtf8("background"));
        background->setGeometry(QRect(283, -6, 191, 91));
        background->setMinimumSize(QSize(191, 91));
        background->setAutoFillBackground(false);
        background->setStyleSheet(QString::fromUtf8("QFrame#background{background-image:url(:/StaticDO/Resources/Background.png)}"));
        background->setFrameShape(QFrame::StyledPanel);
        background->setFrameShadow(QFrame::Raised);
        scrollArea = new QScrollArea(StaticDOClass);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(27, 69, 369, 317));
        scrollArea->setMinimumSize(QSize(369, 317));
        scrollArea->setMaximumSize(QSize(369, 317));
        scrollArea->setSizeIncrement(QSize(369, 317));
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 341, 0));
        scrollAreaWidgetContents->setMinimumSize(QSize(341, 0));
        scrollArea->setWidget(scrollAreaWidgetContents);
        btnConfig = new QPushButton(StaticDOClass);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        btnConfig->setGeometry(QRect(304, 396, 91, 23));
        btnConfig->setMinimumSize(QSize(75, 23));
        label = new QLabel(StaticDOClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 50, 361, 16));
        label->setMinimumSize(QSize(361, 16));
        label->setMaximumSize(QSize(361, 16));
        btnStop = new QPushButton(StaticDOClass);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setGeometry(QRect(690, 330, 111, 23));
        btnStop->setAutoDefault(false);
        btnPause = new QPushButton(StaticDOClass);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(false);
        btnPause->setGeometry(QRect(560, 330, 111, 23));
        btnPause->setAutoDefault(false);
        btnStart = new QPushButton(StaticDOClass);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(430, 330, 111, 23));
        timerFreqLabel = new QLabel(StaticDOClass);
        timerFreqLabel->setObjectName(QString::fromUtf8("timerFreqLabel"));
        timerFreqLabel->setGeometry(QRect(723, 182, 41, 16));
        timerFreqLabel->setMinimumSize(QSize(41, 16));
        timerFreqLabel->setMaximumSize(QSize(41, 16));
        timerTrackBar = new QSlider(StaticDOClass);
        timerTrackBar->setObjectName(QString::fromUtf8("timerTrackBar"));
        timerTrackBar->setGeometry(QRect(610, 180, 111, 21));
        timerTrackBar->setMinimum(1);
        timerTrackBar->setMaximum(1000);
        timerTrackBar->setValue(50);
        timerTrackBar->setOrientation(Qt::Horizontal);
        FFTChoose = new QComboBox(StaticDOClass);
        FFTChoose->setObjectName(QString::fromUtf8("FFTChoose"));
        FFTChoose->setGeometry(QRect(620, 110, 121, 21));
        txtPointCount = new QLineEdit(StaticDOClass);
        txtPointCount->setObjectName(QString::fromUtf8("txtPointCount"));
        txtPointCount->setGeometry(QRect(560, 250, 113, 25));
        txtPointCount->setMinimumSize(QSize(113, 25));
        btnStart2 = new QPushButton(StaticDOClass);
        btnStart2->setObjectName(QString::fromUtf8("btnStart2"));
        btnStart2->setEnabled(true);
        btnStart2->setGeometry(QRect(690, 250, 111, 23));
        label_2 = new QLabel(StaticDOClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 110, 121, 16));
        label_3 = new QLabel(StaticDOClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(480, 180, 111, 16));
        label_4 = new QLabel(StaticDOClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(440, 250, 111, 16));

        retranslateUi(StaticDOClass);

        QMetaObject::connectSlotsByName(StaticDOClass);
    } // setupUi

    void retranslateUi(QDialog *StaticDOClass)
    {
        StaticDOClass->setWindowTitle(QCoreApplication::translate("StaticDOClass", "Static DO", nullptr));
        btnConfig->setText(QCoreApplication::translate("StaticDOClass", "Configure", nullptr));
        label->setText(QCoreApplication::translate("StaticDOClass", "Port No.    Bit7                          4            3                             0         Hex", nullptr));
        btnStop->setText(QCoreApplication::translate("StaticDOClass", "Stop", nullptr));
        btnPause->setText(QCoreApplication::translate("StaticDOClass", "Pause", nullptr));
        btnStart->setText(QCoreApplication::translate("StaticDOClass", "Start", nullptr));
        timerFreqLabel->setText(QCoreApplication::translate("StaticDOClass", "50ms", nullptr));
        txtPointCount->setText(QCoreApplication::translate("StaticDOClass", "400", nullptr));
        btnStart2->setText(QCoreApplication::translate("StaticDOClass", "Start", nullptr));
        label_2->setText(QCoreApplication::translate("StaticDOClass", "Channel select:", nullptr));
        label_3->setText(QCoreApplication::translate("StaticDOClass", "Interval set:", nullptr));
        label_4->setText(QCoreApplication::translate("StaticDOClass", "Output set:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StaticDOClass: public Ui_StaticDOClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATICDO_H
