#ifndef STATICDO_H
#define STATICDO_H

#include <QDialog>
#include <QTimer>
#include "configuredialog.h"
#include "../common/DioPortUI.h"
#include "ui_staticdo.h"

class StaticDO : public QDialog
{
	Q_OBJECT

public:
	StaticDO(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~StaticDO();

	void Initialize();
	void InitializePortPanel();
	void SetConfigureDialog(ConfigureDialog * dialog){configureDialog = dialog;}
	void SetConfigureParameter(ConfigureParameter value){configure = value;}
	void ConfigureDevice();
	void CheckError(ErrorCode errorCode);

private:
	Ui::StaticDOClass ui;
	ConfigureDialog *configureDialog;
	ConfigureParameter configure;
	InstantDoCtrl* instantDoCtrl;
	DioPortUI** m_portPanel;
	QVBoxLayout* layout;
    QTimer *timer;

	int portCount;
	int portPanelLength;
	QString images[3];

private slots:
	void ButtonConfigureClicked();
     void ButtonStart2Clicked();
    void TimerTicked();
	void stateChanged(QObject* sender);
    void ButtonStartClicked();
    void ButttonPauseClicked();
    void SliderValueChanged(int value);
    void ButtonStopClicked();
};

#endif // STATICDO_H
