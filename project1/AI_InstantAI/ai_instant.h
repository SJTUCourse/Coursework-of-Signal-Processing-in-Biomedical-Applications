#ifndef AI_INSTANT_H
#define AI_INSTANT_H

#include <QtWidgets/QDialog>
#include <QtCore/QtCore>
#include <QFileDialog>
#include <QTimer>
#include <QMouseEvent>
#include "ui_ai_instant.h"
#include "../common/simplegraph.h"
#include "configuredialog.h"
#include "data_processing.h"

class AI_Instant : public QDialog
{
	Q_OBJECT

public:
	AI_Instant(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~AI_Instant();

	void Initialize();
	void ConfigureDevice();
	void ConfigureGraph();
	void CheckError(ErrorCode errorCode);
	void RefreshList();
	void SetConfigureDialog(ConfigureDialog *dialog){this->configDialog = dialog;}
	void SetConfigureParameter(ConfigureParameter value){this->configure = value;}
    void mouseMoveEvent(QMouseEvent* event);   /// Get the coordinate of the mouse

private:
	Ui::AI_InstantFrame ui;
	SimpleGraph *graph;
	ConfigureDialog *configDialog;
	ConfigureParameter configure;
	InstantAiCtrl *instantAiCtrl;
	double scaledData[16];
	QTimer *timer;
    Data_Processing Data;   /// Save all data

private slots:
	void TimerTicked();
	void SliderValueChanged(int value);
    void SetXRangeSliderChanged(int value);
    void SetYRangeSliderChanged(int value);
	void ButtonStartClicked();
	void ButtonConfigureClicked();
	void ButttonPauseClicked();
	void ButtonStopClicked();
    void ButtonSaveDataClicked();   /// The slot function when ButtonSaveDataClicked
    void ButtonOpenDataClicked();   /// The slot function when ButtonOpenDataClicked
    void FFTShowFunction();
};

#endif // AI_INSTANT_H
