#include "staticdo.h"
#include <QMessageBox>

StaticDO::StaticDO(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
	this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

   instantDoCtrl = InstantDoCtrl::Create();
	m_portPanel = NULL;
	portPanelLength = 0;

	this->layout = new QVBoxLayout(ui.scrollAreaWidgetContents);	

	images[0] = "background:url(:/StaticDO/Resources/ButtonUp.png)";
	images[1] = "background:url(:/StaticDO/Resources/ButtonDown.png)";
	images[2] = "background:url(:/StaticDO/Resources/ButtonDisabled.png)";

    timer = new QTimer(this);

    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(ButtonStartClicked()));
    connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(ButttonPauseClicked()));
    connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(ButtonStopClicked()));
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTicked()));
	connect(ui.btnConfig, SIGNAL(clicked()), this, SLOT(ButtonConfigureClicked()));
    connect(ui.timerTrackBar, SIGNAL(valueChanged(int)), this, SLOT(SliderValueChanged(int)));
    connect(ui.btnStart2, SIGNAL(clicked()), this, SLOT(ButtonStart2Clicked()));
}

StaticDO::~StaticDO()
{

}

void StaticDO::Initialize() {
	//set the title of the form.
	setWindowTitle(tr("Static DO - Run(") + configure.deviceName + tr(")"));

	ConfigureDevice();
	InitializePortPanel();
}

void StaticDO::ConfigureDevice() {
    std::wstring description = configure.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

	ErrorCode errorCode = Success;
	errorCode = instantDoCtrl->setSelectedDevice(selected);
	CheckError(errorCode);
	errorCode = instantDoCtrl->LoadProfile(configure.profilePath);
	CheckError(errorCode);
	portCount = instantDoCtrl->getPortCount();

}

void StaticDO::InitializePortPanel()
{
	//remove the old port panel
    if (m_portPanel != NULL)
    {
		int height = ui.scrollAreaWidgetContents->height();
        for (int i = 0; i < portPanelLength; i++)
        {
			this->layout->removeWidget(m_portPanel[i]);
			ui.scrollAreaWidgetContents->setGeometry(0, 0, 341, height - (i + 1) * 45);
            if (m_portPanel[i] != NULL)
            {
				delete m_portPanel[i];
				m_portPanel[i] = NULL;
			}
		}

	}

	DioFeatures * features = instantDoCtrl->getFeatures();
	Array<uint8>* portMasks = features->getDoDataMask();//getDataMask();

	quint8 *portStates = new quint8[portCount];
	ErrorCode errorCode = Success;
    errorCode = instantDoCtrl->Read(0, portCount, portStates);
    CheckError(errorCode);

	m_portPanel = new DioPortUI*[portCount];
    portPanelLength = portCount;
    for (int i = 0; i < 8; i++)
    {
       ui.FFTChoose->addItem(QString("%1").arg(i));
     }
    ///
    for (int i = 0; i < portCount; i++)
    {
    ///    ui.FFTChoose->addItem(QString("%1").arg(i));
		ui.scrollAreaWidgetContents->setGeometry(0, 0, 341, (i + 1) * 45);
		m_portPanel[i] = new DioPortUI(0, 0, i, (quint8)0, images); 
		m_portPanel[i]->setMask(portMasks->getItem(i));
		m_portPanel[i]->setIsEditable(true);
		m_portPanel[i]->setState(portStates[i]);
		m_portPanel[i]->JudgeDirection(portMasks->getItem(i));

		connect(m_portPanel[i], SIGNAL(stateChanged(QObject*)), this, SLOT(stateChanged(QObject*)));

		this->layout->addWidget(m_portPanel[i]);
	}
}

void StaticDO::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
	{
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8).toUpper();
		QMessageBox::information(this, "Warning Information", message);
	}
}

void StaticDO::ButtonConfigureClicked()
{
	int dialogResult = configureDialog->exec();
    if (dialogResult == QDialog::Accepted)
    {
		configure = configureDialog->GetConfigureParameter();
		Initialize();
	}
}

void StaticDO::stateChanged(QObject* sender)
{
    DioPortUI* panel = (DioPortUI*) sender;
   quint8 status =  panel->getState();

	ErrorCode errorCode = Success;
    errorCode = instantDoCtrl->Write(panel->getKey(), 1, &status);

    CheckError(errorCode);

}

void StaticDO::TimerTicked()
{


       static int flag = 0;

       if(ui.FFTChoose->currentText().toInt()==0)
       {
        if(flag%2==0)
        {
        quint8 status=0b00000001;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==1)
       {
        if(flag%2==0)
        {
        quint8 status=0b00000010;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }if(ui.FFTChoose->currentText().toInt()==2)
       {
        if(flag%2==0)
        {
        quint8 status=0b00000100;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==3)
       {
        if(flag%2==0)
        {
        quint8 status=0b00001000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==4)
       {
        if(flag%2==0)
        {
        quint8 status=0b00010000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==5)
       {
        if(flag%2==0)
        {
        quint8 status=0b00100000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==6)
       {
        if(flag%2==0)
        {
        quint8 status=0b01000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }

       if(ui.FFTChoose->currentText().toInt()==7)
       {
        if(flag%2==0)
        {
        quint8 status=0b10000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       if(flag%2==1)
        {
        quint8 status=0b00000000;
        ErrorCode errorCode = Success;
        errorCode = instantDoCtrl->Write(0, 1, &status);
        CheckError(errorCode);
        }

       }


       flag++;

}

void StaticDO::ButtonStartClicked()
{
    timer->start(ui.timerTrackBar->value()/2);

    ui.btnConfig->setEnabled(false);
    ui.btnStart->setEnabled(false);
    ui.btnPause->setEnabled(true);
    ui.btnStop->setEnabled(true);
}

void StaticDO::ButttonPauseClicked()
{
    timer->stop();

    ui.btnConfig->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(true);
}

void StaticDO::ButtonStopClicked()
{
    timer->stop();

    ui.btnConfig->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(false);

}

void StaticDO::SliderValueChanged(int value)
{
    timer->setInterval(ui.timerTrackBar->value()/2);
    ui.timerFreqLabel->setText(QString("%1").arg(ui.timerTrackBar->value()) + tr("ms"));
}


void StaticDO::ButtonStart2Clicked()
{
    timer->stop();
    ui.btnConfig->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(true);


    int counts=ui.txtPointCount->text().toInt();


    for (int i=0; i<counts/(ui.timerTrackBar->value()/2);i++)
    {
       TimerTicked();
       QTime reachTime = QTime::currentTime().addMSecs(ui.timerTrackBar->value()/2);
       while (QTime::currentTime()<reachTime)
       {
           QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
       }
    }



}
