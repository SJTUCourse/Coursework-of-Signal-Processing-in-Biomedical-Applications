#ifndef STATICAO_H
#define STATICAO_H

#include <QDialog>
#include <QPushButton>
#include <QtWidgets>
#include <QTimer>
#include <vector>
#include "ui_staticao.h"
#include "configuredialog.h"
#include "../common/WaveformGenerator.h"

using namespace std;

class StaticAO : public QDialog
{
	Q_OBJECT

public:
	StaticAO(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~StaticAO();

	void Initialize();
	void ConfigureDevice();
	void CheckError(ErrorCode errorCode);
	void SetConfigureDialog(ConfigureDialog *dialog){this->configDialog = dialog;}
	void SetConfigureParameter(ConfigureParameter value){this->configure = value;}
	void ConfigurePanel();

private:
	Ui::StaticAOClass ui;
	ConfigureDialog *configDialog;
	ConfigureParameter configure;
	InstantAoCtrl * instantAoCtrl;
    vector<double> OutputChanneloneData;
    vector<double> OutputChanneltwoData;

    int channelStart;
    int channelCount;
    double dataScaled[2];
    WaveformParameter m_waveParam[2];    ///   Save the number of High,Low level
    WaveformGenerator *waveformGenerator1;
    WaveformGenerator *waveformGenerator2;
	QPushButton* buttons[6];
	int m_wavePtIdx[2];
    bool m_waveSeled[2];
	QTimer *timer;
	QString strs[6];
	QButtonGroup* buttonGroup1;
	QButtonGroup* buttonGroup2;

private slots:
    void ButtonStartClicked();
    void ButtonStart2Clicked();
    void ButttonPauseClicked();
    void ButtonOpenDataClicked();
    void ButtonStopClicked();
	void TimerTicked();
	void SliderValueChanged(int value);
    void ButtonConfigureClicked();
	void ManualClicked(int id);
	void WaveButtonClicked(int id);


};

#endif // STATICAO_H
