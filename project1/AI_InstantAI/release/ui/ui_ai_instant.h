/********************************************************************************
** Form generated from reading UI file 'ai_instant.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AI_INSTANT_H
#define UI_AI_INSTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_AI_InstantFrame
{
public:
    QLabel *lblYCoordinateMax;
    QLabel *lblYCoordinateMid;
    QLabel *lblYCoordinateMin;
    QFrame *graphFrame;
    QLabel *lblXCoordinateStart;
    QLabel *lblXCoordinateEnd;
    QListWidget *listWidget;
    QLabel *lblInterval;
    QPushButton *btnConfigure;
    QPushButton *btnStart;
    QPushButton *btnPause;
    QPushButton *btnStop;
    QLabel *label_Y;
    QLabel *label_Y_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSpinBox *SetXRangeSpinBox_X;
    QSlider *SetXRangeSlider_X;
    QLabel *label;
    QLineEdit *MouseCoordinate;
    QPushButton *btnOpenData;
    QPushButton *btnSaveData;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QSpinBox *SetYRangeSpinBox_Y;
    QSlider *SetYRangeSlider_Y;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QSpinBox *edtTimerValue;
    QSlider *sldTimerValue;
    QCustomPlot *FFTShow;
    QLabel *label_3;
    QCustomPlot *FilterFFTShow;
    QComboBox *FilterChoose;
    QSpinBox *Frequency;
    QCustomPlot *OriginShow;
    QCustomPlot *OriginShow2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_2;
    QComboBox *FFTChoose;

    void setupUi(QDialog *AI_InstantFrame)
    {
        if (AI_InstantFrame->objectName().isEmpty())
            AI_InstantFrame->setObjectName(QString::fromUtf8("AI_InstantFrame"));
        AI_InstantFrame->resize(1627, 785);
        AI_InstantFrame->setMinimumSize(QSize(762, 520));
        AI_InstantFrame->setMaximumSize(QSize(7620, 5200));
        AI_InstantFrame->setAutoFillBackground(true);
        lblYCoordinateMax = new QLabel(AI_InstantFrame);
        lblYCoordinateMax->setObjectName(QString::fromUtf8("lblYCoordinateMax"));
        lblYCoordinateMax->setGeometry(QRect(19, 110, 46, 20));
        lblYCoordinateMax->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblYCoordinateMid = new QLabel(AI_InstantFrame);
        lblYCoordinateMid->setObjectName(QString::fromUtf8("lblYCoordinateMid"));
        lblYCoordinateMid->setGeometry(QRect(19, 270, 46, 16));
        lblYCoordinateMid->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lblYCoordinateMin = new QLabel(AI_InstantFrame);
        lblYCoordinateMin->setObjectName(QString::fromUtf8("lblYCoordinateMin"));
        lblYCoordinateMin->setGeometry(QRect(19, 432, 46, 16));
        lblYCoordinateMin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        graphFrame = new QFrame(AI_InstantFrame);
        graphFrame->setObjectName(QString::fromUtf8("graphFrame"));
        graphFrame->setGeometry(QRect(66, 109, 660, 340));
        graphFrame->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        graphFrame->setFrameShape(QFrame::StyledPanel);
        graphFrame->setFrameShadow(QFrame::Raised);
        lblXCoordinateStart = new QLabel(AI_InstantFrame);
        lblXCoordinateStart->setObjectName(QString::fromUtf8("lblXCoordinateStart"));
        lblXCoordinateStart->setGeometry(QRect(69, 450, 71, 16));
        lblXCoordinateStart->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        lblXCoordinateEnd = new QLabel(AI_InstantFrame);
        lblXCoordinateEnd->setObjectName(QString::fromUtf8("lblXCoordinateEnd"));
        lblXCoordinateEnd->setGeometry(QRect(633, 450, 91, 16));
        lblXCoordinateEnd->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listWidget = new QListWidget(AI_InstantFrame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(87, 498, 341, 51));
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        listWidget->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setProperty("isWrapping", QVariant(true));
        lblInterval = new QLabel(AI_InstantFrame);
        lblInterval->setObjectName(QString::fromUtf8("lblInterval"));
        lblInterval->setGeometry(QRect(570, 660, 151, 16));
        lblInterval->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btnConfigure = new QPushButton(AI_InstantFrame);
        btnConfigure->setObjectName(QString::fromUtf8("btnConfigure"));
        btnConfigure->setEnabled(true);
        btnConfigure->setGeometry(QRect(70, 592, 101, 23));
        btnConfigure->setAutoDefault(false);
        btnStart = new QPushButton(AI_InstantFrame);
        btnStart->setObjectName(QString::fromUtf8("btnStart"));
        btnStart->setEnabled(true);
        btnStart->setGeometry(QRect(479, 590, 75, 23));
        btnPause = new QPushButton(AI_InstantFrame);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setEnabled(false);
        btnPause->setGeometry(QRect(566, 590, 75, 23));
        btnPause->setAutoDefault(false);
        btnStop = new QPushButton(AI_InstantFrame);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));
        btnStop->setEnabled(false);
        btnStop->setGeometry(QRect(652, 590, 75, 23));
        btnStop->setAutoDefault(false);
        label_Y = new QLabel(AI_InstantFrame);
        label_Y->setObjectName(QString::fromUtf8("label_Y"));
        label_Y->setGeometry(QRect(340, 660, 111, 16));
        label_Y_2 = new QLabel(AI_InstantFrame);
        label_Y_2->setObjectName(QString::fromUtf8("label_Y_2"));
        label_Y_2->setGeometry(QRect(89, 660, 111, 16));
        layoutWidget = new QWidget(AI_InstantFrame);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 682, 151, 52));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        SetXRangeSpinBox_X = new QSpinBox(layoutWidget);
        SetXRangeSpinBox_X->setObjectName(QString::fromUtf8("SetXRangeSpinBox_X"));

        verticalLayout_2->addWidget(SetXRangeSpinBox_X);

        SetXRangeSlider_X = new QSlider(layoutWidget);
        SetXRangeSlider_X->setObjectName(QString::fromUtf8("SetXRangeSlider_X"));
        SetXRangeSlider_X->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(SetXRangeSlider_X);

        label = new QLabel(AI_InstantFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(525, 488, 168, 28));
        MouseCoordinate = new QLineEdit(AI_InstantFrame);
        MouseCoordinate->setObjectName(QString::fromUtf8("MouseCoordinate"));
        MouseCoordinate->setGeometry(QRect(520, 520, 180, 24));
        btnOpenData = new QPushButton(AI_InstantFrame);
        btnOpenData->setObjectName(QString::fromUtf8("btnOpenData"));
        btnOpenData->setGeometry(QRect(220, 592, 101, 23));
        btnSaveData = new QPushButton(AI_InstantFrame);
        btnSaveData->setObjectName(QString::fromUtf8("btnSaveData"));
        btnSaveData->setGeometry(QRect(330, 592, 101, 23));
        layoutWidget1 = new QWidget(AI_InstantFrame);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(321, 682, 151, 52));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SetYRangeSpinBox_Y = new QSpinBox(layoutWidget1);
        SetYRangeSpinBox_Y->setObjectName(QString::fromUtf8("SetYRangeSpinBox_Y"));

        verticalLayout->addWidget(SetYRangeSpinBox_Y);

        SetYRangeSlider_Y = new QSlider(layoutWidget1);
        SetYRangeSlider_Y->setObjectName(QString::fromUtf8("SetYRangeSlider_Y"));
        SetYRangeSlider_Y->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(SetYRangeSlider_Y);

        layoutWidget2 = new QWidget(AI_InstantFrame);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(570, 680, 151, 52));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        edtTimerValue = new QSpinBox(layoutWidget2);
        edtTimerValue->setObjectName(QString::fromUtf8("edtTimerValue"));

        verticalLayout_3->addWidget(edtTimerValue);

        sldTimerValue = new QSlider(layoutWidget2);
        sldTimerValue->setObjectName(QString::fromUtf8("sldTimerValue"));
        sldTimerValue->setEnabled(false);
        sldTimerValue->setMinimum(10);
        sldTimerValue->setMaximum(1000);
        sldTimerValue->setSingleStep(10);
        sldTimerValue->setValue(200);
        sldTimerValue->setOrientation(Qt::Horizontal);
        sldTimerValue->setTickPosition(QSlider::NoTicks);

        verticalLayout_3->addWidget(sldTimerValue);

        FFTShow = new QCustomPlot(AI_InstantFrame);
        FFTShow->setObjectName(QString::fromUtf8("FFTShow"));
        FFTShow->setGeometry(QRect(760, 220, 381, 201));
        label_3 = new QLabel(AI_InstantFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(620, 40, 311, 16));
        FilterFFTShow = new QCustomPlot(AI_InstantFrame);
        FilterFFTShow->setObjectName(QString::fromUtf8("FilterFFTShow"));
        FilterFFTShow->setGeometry(QRect(1170, 220, 381, 201));
        FilterChoose = new QComboBox(AI_InstantFrame);
        FilterChoose->addItem(QString());
        FilterChoose->addItem(QString());
        FilterChoose->setObjectName(QString::fromUtf8("FilterChoose"));
        FilterChoose->setGeometry(QRect(1284, 120, 111, 21));
        Frequency = new QSpinBox(AI_InstantFrame);
        Frequency->setObjectName(QString::fromUtf8("Frequency"));
        Frequency->setGeometry(QRect(1420, 120, 111, 21));
        OriginShow = new QCustomPlot(AI_InstantFrame);
        OriginShow->setObjectName(QString::fromUtf8("OriginShow"));
        OriginShow->setGeometry(QRect(1170, 500, 381, 211));
        OriginShow2 = new QCustomPlot(AI_InstantFrame);
        OriginShow2->setObjectName(QString::fromUtf8("OriginShow2"));
        OriginShow2->setGeometry(QRect(760, 500, 381, 211));
        label_4 = new QLabel(AI_InstantFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1180, 120, 91, 16));
        label_5 = new QLabel(AI_InstantFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(900, 460, 111, 16));
        label_6 = new QLabel(AI_InstantFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1270, 460, 181, 20));
        label_7 = new QLabel(AI_InstantFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(920, 180, 71, 16));
        label_8 = new QLabel(AI_InstantFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(1290, 180, 141, 20));
        label_2 = new QLabel(AI_InstantFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(821, 120, 120, 16));
        FFTChoose = new QComboBox(AI_InstantFrame);
        FFTChoose->setObjectName(QString::fromUtf8("FFTChoose"));
        FFTChoose->setGeometry(QRect(950, 120, 121, 21));
        QWidget::setTabOrder(btnConfigure, btnStart);
        QWidget::setTabOrder(btnStart, btnPause);
        QWidget::setTabOrder(btnPause, btnStop);
        QWidget::setTabOrder(btnStop, sldTimerValue);
        QWidget::setTabOrder(sldTimerValue, listWidget);

        retranslateUi(AI_InstantFrame);

        QMetaObject::connectSlotsByName(AI_InstantFrame);
    } // setupUi

    void retranslateUi(QDialog *AI_InstantFrame)
    {
        AI_InstantFrame->setWindowTitle(QCoreApplication::translate("AI_InstantFrame", "AI_Instant", nullptr));
        lblYCoordinateMax->setText(QCoreApplication::translate("AI_InstantFrame", "10.0V", nullptr));
        lblYCoordinateMid->setText(QCoreApplication::translate("AI_InstantFrame", "0.0V", nullptr));
        lblYCoordinateMin->setText(QCoreApplication::translate("AI_InstantFrame", "-10.0V", nullptr));
        lblXCoordinateStart->setText(QCoreApplication::translate("AI_InstantFrame", "0Sec", nullptr));
        lblXCoordinateEnd->setText(QCoreApplication::translate("AI_InstantFrame", "10Sec", nullptr));
        lblInterval->setText(QCoreApplication::translate("AI_InstantFrame", "Sample Interval:ms", nullptr));
        btnConfigure->setText(QCoreApplication::translate("AI_InstantFrame", "Configure", nullptr));
        btnStart->setText(QCoreApplication::translate("AI_InstantFrame", "Start", nullptr));
        btnPause->setText(QCoreApplication::translate("AI_InstantFrame", "Pause", nullptr));
        btnStop->setText(QCoreApplication::translate("AI_InstantFrame", "Stop", nullptr));
        label_Y->setText(QCoreApplication::translate("AI_InstantFrame", "SetYValueRange", nullptr));
        label_Y_2->setText(QCoreApplication::translate("AI_InstantFrame", "SetXValueRange", nullptr));
        label->setText(QCoreApplication::translate("AI_InstantFrame", "The Mouse Coordinate:", nullptr));
        btnOpenData->setText(QCoreApplication::translate("AI_InstantFrame", "OpenData", nullptr));
        btnSaveData->setText(QCoreApplication::translate("AI_InstantFrame", "SaveData", nullptr));
        label_3->setText(QCoreApplication::translate("AI_InstantFrame", "Signal process: Shiyu Sun & Wanshan Liu", nullptr));
        FilterChoose->setItemText(0, QCoreApplication::translate("AI_InstantFrame", "LowPass", nullptr));
        FilterChoose->setItemText(1, QCoreApplication::translate("AI_InstantFrame", "HighPass", nullptr));

        label_4->setText(QCoreApplication::translate("AI_InstantFrame", "Filter Set:", nullptr));
        label_5->setText(QCoreApplication::translate("AI_InstantFrame", "Original plot", nullptr));
        label_6->setText(QCoreApplication::translate("AI_InstantFrame", "Filtered original plot", nullptr));
        label_7->setText(QCoreApplication::translate("AI_InstantFrame", "FFT plot", nullptr));
        label_8->setText(QCoreApplication::translate("AI_InstantFrame", "Filtered FFT plot", nullptr));
        label_2->setText(QCoreApplication::translate("AI_InstantFrame", "Channel Choose:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AI_InstantFrame: public Ui_AI_InstantFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AI_INSTANT_H
