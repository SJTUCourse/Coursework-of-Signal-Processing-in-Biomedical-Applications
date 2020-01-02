#include "staticao.h"
#include "Qtime"
#include "QApplication"
#include <QMessageBox>

StaticAO::StaticAO(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
	this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

    this->buttonGroup1 = new QButtonGroup();
    this->buttonGroup1->addButton(ui.BtnSineA, 0);
	this->buttonGroup1->addButton(ui.BtnTriangleA, 1);
	this->buttonGroup1->addButton(ui.BtnSquareA, 2);
	this->buttonGroup1->addButton(ui.BtnSineB, 3);
	this->buttonGroup1->addButton(ui.BtnTriangleB, 4);
	this->buttonGroup1->addButton(ui.BtnSquareB, 5);
	this->buttonGroup1->setExclusive(false);

	this->buttonGroup2 = new QButtonGroup();
	this->buttonGroup2->addButton(ui.BtnManualA, 0);
	this->buttonGroup2->addButton(ui.BtnManualB, 1);
	this->buttonGroup2->setExclusive(false);

	this->buttons[0] = ui.BtnSineA;
	this->buttons[1] = ui.BtnTriangleA;
	this->buttons[2] = ui.BtnSquareA;
	this->buttons[3] = ui.BtnSineB;
	this->buttons[4] = ui.BtnTriangleB;
	this->buttons[5] = ui.BtnSquareB;
	
    /// Add background pictures
	strs[0] = "background:url(:/StaticAO/Resources/sine.png)";
	strs[1] = "background:url(:/StaticAO/Resources/sine_down.png)";
	strs[2] = "background:url(:/StaticAO/Resources/triangle.png)";
	strs[3] = "background:url(:/StaticAO/Resources/triangle_down.png)";
	strs[4] = "background:url(:/StaticAO/Resources/square.png)";
	strs[5] = "background:url(:/StaticAO/Resources/square_down.png)";

    instantAoCtrl = InstantAoCtrl::Create();
	this->m_waveSeled[0] = false;
	this->m_waveSeled[1] = false;
	
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimerTicked()));
	connect(ui.timerTrackBar, SIGNAL(valueChanged(int)), this, SLOT(SliderValueChanged(int)));
    connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(ButtonStartClicked()));
    connect(ui.btnStart2, SIGNAL(clicked()), this, SLOT(ButtonStart2Clicked()));
    connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(ButttonPauseClicked()));
    connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(ButtonStopClicked()));
    connect(ui.btnOpenData, SIGNAL(clicked()), this, SLOT(ButtonOpenDataClicked()));
	connect(ui.btnConfigure, SIGNAL(clicked()), this, SLOT(ButtonConfigureClicked()));
	connect(this->buttonGroup1, SIGNAL(buttonClicked(int)), this, SLOT(WaveButtonClicked(int)));
	connect(this->buttonGroup2, SIGNAL(buttonClicked(int)), this, SLOT(ManualClicked(int)));
}

StaticAO::~StaticAO()
{

}

void StaticAO::Initialize()
{
	//set the title of the form.
	this->setWindowTitle(tr("Static AO - Run(") + configure.deviceName + tr(")"));

	//initialize these variables
    channelStart = 0;
    channelCount = 0;

    waveformGenerator1 = new WaveformGenerator(configure.pointCountPerWave1);
    waveformGenerator2 = new WaveformGenerator(configure.pointCountPerWave2);

	ConfigureDevice();
	ConfigurePanel();

	//initialize a timer which drive the data acquisition.
    timer->stop();
}

void StaticAO::ConfigureDevice()
{
	ErrorCode errorCode = Success;
    std::wstring description = configure.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());
	errorCode = instantAoCtrl->setSelectedDevice(selected);
	CheckError(errorCode);
	errorCode = instantAoCtrl->LoadProfile(configure.profilePath);
	CheckError(errorCode);

	for (int i = 0; i < instantAoCtrl->getChannels()->getCount(); i++) {
		errorCode = instantAoCtrl->getChannels()->getItem(i).setValueRange(configure.valueRange);
		CheckError(errorCode);
	}
}

void StaticAO::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
    {
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8).toUpper();
		QMessageBox::information(this, "Warning Information", message);
	}
}

void StaticAO::ButtonConfigureClicked()
{
	timer->stop();
	int dialogResult = configDialog->exec();
    if (dialogResult == QDialog::Accepted)
    {
		configure = configDialog->GetConfigureParameter();
		Initialize();
	}
}

void StaticAO::ConfigurePanel()
{
    if (configure.channelCount == 1)
    {
		channelStart = configure.channelStart;
		channelCount = 1;

		ui.BtnSineB->setEnabled(false);
		ui.BtnTriangleB->setEnabled(false);
		ui.BtnSquareB->setEnabled(false);
		ui.BtnManualB->setEnabled(false);
		ui.txtboxHiLevelB->setEnabled(false);
		ui.txtboxLoLevelB->setEnabled(false);
		ui.txtboxValueB->setEnabled(false);
		ui.chLabelB->setText(tr(""));
    }

    else
    {
		channelStart = configure.channelStart;
		channelCount = 2;

		ui.BtnSineB->setEnabled(true);
		ui.BtnTriangleB->setEnabled(true);
		ui.BtnSquareB->setEnabled(true);
		ui.BtnManualB->setEnabled(true);
		ui.txtboxHiLevelB->setEnabled(true);
		ui.txtboxLoLevelB->setEnabled(true);
		ui.txtboxValueB->setEnabled(true);
		ui.chLabelB->setText(QString("%1").arg((channelStart + 1) % instantAoCtrl->getChannelCount()));
	}
	ui.chLabelA->setText(QString("%1").arg(channelStart));
}

void StaticAO::SliderValueChanged(int value)
{
    timer->setInterval(ui.timerTrackBar->value());
	ui.timerFreqLabel->setText(QString("%1").arg(ui.timerTrackBar->value()) + tr("ms"));

    ui.OutputdataShow->clearGraphs();
    OutputChanneloneData.clear();
    OutputChanneltwoData.clear();
    m_wavePtIdx[0]=0;
    m_wavePtIdx[1]=0;
}

void StaticAO::ButtonStartClicked()
{
    timer->start(ui.timerTrackBar->value());

    ui.btnConfigure->setEnabled(false);
    ui.btnStart->setEnabled(false);
    ui.btnPause->setEnabled(true);
    ui.btnStop->setEnabled(true);
    ui.btnStart2->setEnabled(false);
}

void StaticAO::ButttonPauseClicked()
{
    timer->stop();

    ui.btnConfigure->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(true);
    ui.btnStart2->setEnabled(true);
}

void StaticAO::ButtonStopClicked()
{
    timer->stop();

    ui.btnConfigure->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(false);
    ui.btnStart2->setEnabled(true);

    ui.OutputdataShow->clearGraphs();
    OutputChanneloneData.clear();
    OutputChanneltwoData.clear();
    m_wavePtIdx[0]=0;
    m_wavePtIdx[1]=0;

}

void StaticAO::WaveButtonClicked(int id)
{
	int seledCH, baseIdx, imgIdx;

	seledCH = id / 3;
	baseIdx = seledCH * 3;

    ///   Turn off other pictures
    for (int i = baseIdx; i < baseIdx + 3; i++)
    {
        if (i != id && buttons[i]->isChecked())
        {
			imgIdx = (i- baseIdx) * 2;
			buttons[i]->setChecked(false);
			buttons[i]->setStyleSheet(strs[imgIdx]);
		}
	}

    ///   Convert own state
    if (buttons[id]->isChecked())
    {
        buttons[id]->setStyleSheet(strs[(id - baseIdx) * 2 + 1]);
    }
    else
    {
        buttons[id]->setStyleSheet(strs[(id - baseIdx) * 2]);
        dataScaled[seledCH] = 0;
	}

	m_waveSeled[seledCH] = buttons[id]->isChecked();
	m_waveParam[seledCH].Style = (WaveformStyle)(id % 3);

    ///   Save the number of High,Low level
    if (seledCH == 0)
    {
		m_waveParam[seledCH].HighLevel = ui.txtboxHiLevelA->text().toDouble();
		m_waveParam[seledCH].LowLevel = ui.txtboxLoLevelA->text().toDouble();
        ///OutputChanneloneData.clear();
    }

    else
    {
		m_waveParam[seledCH].HighLevel = ui.txtboxHiLevelB->text().toDouble();
		m_waveParam[seledCH].LowLevel = ui.txtboxLoLevelB->text().toDouble();
        ///OutputChanneltwoData.clear();
	}

	m_wavePtIdx[seledCH] = 0;
}

void StaticAO::ManualClicked(int id)

{
	int ch, baseIdx;

    ///   manual ouput button click
	ch = id;
	baseIdx = id * 3;

    ///   Turn off other pictures
    for (int i = 0; i < 3; i++)
    {
        if (buttons[i + baseIdx]->isChecked())
        {
			buttons[i + baseIdx]->setChecked(false);
			buttons[i + baseIdx]->setStyleSheet(strs[i * 2]);
		}
	}

	m_waveSeled[ch] = false;

    if (ch == 0)
    {
		dataScaled[ch] = ui.txtboxValueA->text().toDouble();
        ///OutputChanneloneData.clear();
    }
    else
    {
		dataScaled[ch] = ui.txtboxValueB->text().toDouble();
       /// OutputChanneltwoData.clear();
	}
}

void StaticAO::TimerTicked()
{
    for (int i = 0; i < 2; i++)
    {
        if (m_waveSeled[i])
        {
            if (i==0)
            {
                dataScaled[i] = waveformGenerator1->GetOnePoint(m_waveParam[i].Style, m_wavePtIdx[i], m_waveParam[i].HighLevel, m_waveParam[i].LowLevel);
                m_wavePtIdx[i] = (m_wavePtIdx[i] + 1) % configure.pointCountPerWave1;
            }
            else
            {
                dataScaled[i] = waveformGenerator2->GetOnePoint(m_waveParam[i].Style, m_wavePtIdx[i], m_waveParam[i].HighLevel, m_waveParam[i].LowLevel);
                m_wavePtIdx[i] = (m_wavePtIdx[i] + 1) % configure.pointCountPerWave2;
            }
		}
	}

    ErrorCode errorCode = Success;
    /*for (int i=0; i<2 ;i++)
    {
        if (dataScaled[i]<0)
        {
            dataScaled[i]=0;
        }
        if (dataScaled[i]>5)
        {
            dataScaled[i]=5;
        }
    }*/
	errorCode = instantAoCtrl->Write(channelStart, channelCount, dataScaled);

    if (errorCode != Success)
    {
		timer->stop();
		CheckError(errorCode);
	}

    /// Show Output data
    OutputChanneloneData.push_back(dataScaled[0]);
    OutputChanneltwoData.push_back(dataScaled[1]);

    ui.OutputdataShow->clearGraphs();

    ui.OutputdataShow->legend->setVisible(true);
    //设定右上角图形标注的字体
    ui.OutputdataShow->legend->setFont(QFont("Helvetica", 9));

    QVector<double> x1(OutputChanneloneData.size()),y1(OutputChanneloneData.size());

        for(int i=0;i<OutputChanneloneData.size();i++)
        {
            x1[i] = i * ui.timerTrackBar->value() ;
            y1[i] = OutputChanneloneData[i];
        }

        ui.OutputdataShow->addGraph();
        //设置画笔
        ui.OutputdataShow->graph(0)->setPen(QPen(Qt::red));
        //设置右上角图形标注名称
        ui.OutputdataShow->graph(0)->setName("Channel 1");
        //传入数据，setData的两个参数类型为double
        ui.OutputdataShow->graph(0)->setData(x1,y1);

        if (channelCount==2)
        {
        QVector<double> x2(OutputChanneltwoData.size()),y2(OutputChanneltwoData.size());

            for(int i=0;i<OutputChanneltwoData.size();i++)
            {
                x2[i] = i * ui.timerTrackBar->value();
                y2[i] = OutputChanneltwoData[i];
            }

        ui.OutputdataShow->addGraph();
        //设置画笔
        ui.OutputdataShow->graph(1)->setPen(QPen(Qt::green));
        //设置右上角图形标注名称
        ui.OutputdataShow->graph(1)->setName("Channel 2");
        //传入数据，setData的两个参数类型为double
        ui.OutputdataShow->graph(1)->setData(x2,y2);
        }

        ui.OutputdataShow->rescaleAxes();

        ui.OutputdataShow->replot();


}

void StaticAO::ButtonStart2Clicked()
{
    timer->stop();
    ui.btnConfigure->setEnabled(true);
    ui.btnPause->setEnabled(false);
    ui.btnStart->setEnabled(true);
    ui.btnStop->setEnabled(true);


    int counts=ui.txtPointCount->text().toInt();

    for (int j=0; j<counts; j++)

    {

    for (int i = 0; i < 2; i++)
    {
        if (m_waveSeled[i])
        {
            if (i==0)
            {
                dataScaled[i] = waveformGenerator1->GetOnePoint(m_waveParam[i].Style, m_wavePtIdx[i], m_waveParam[i].HighLevel, m_waveParam[i].LowLevel);
                m_wavePtIdx[i] = (m_wavePtIdx[i] + 1) % configure.pointCountPerWave1;
            }
            else
            {
                dataScaled[i] = waveformGenerator2->GetOnePoint(m_waveParam[i].Style, m_wavePtIdx[i], m_waveParam[i].HighLevel, m_waveParam[i].LowLevel);
                m_wavePtIdx[i] = (m_wavePtIdx[i] + 1) % configure.pointCountPerWave2;
            }
        }
    }

    ErrorCode errorCode = Success;
    for (int i=0; i<2 ;i++)
    {
        if (dataScaled[i]<0)
        {
            dataScaled[i]=0;
        }
        if (dataScaled[i]>5)
        {
            dataScaled[i]=5;
        }
    }
    errorCode = instantAoCtrl->Write(channelStart, channelCount, dataScaled);
    if (errorCode != Success)
    {
        timer->stop();
        CheckError(errorCode);
    }

    QTime reachTime = QTime::currentTime().addMSecs(ui.timerTrackBar->value());
    while (QTime::currentTime()<reachTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    /// Show Output data
    OutputChanneloneData.push_back(dataScaled[0]);
    if (configure.channelCount==2)
    {
    OutputChanneltwoData.push_back(dataScaled[1]);
    }

    ui.OutputdataShow->clearGraphs();

    ui.OutputdataShow->legend->setVisible(true);
    //设定右上角图形标注的字体
    ui.OutputdataShow->legend->setFont(QFont("Helvetica", 9));

    QVector<double> x1(OutputChanneloneData.size()),y1(OutputChanneloneData.size());

        for(int i=0;i<OutputChanneloneData.size();i++)
        {
            x1[i] = i * ui.timerTrackBar->value() ;
            y1[i] = OutputChanneloneData[i];
        }

        ui.OutputdataShow->addGraph();
        //设置画笔
        ui.OutputdataShow->graph(0)->setPen(QPen(Qt::red));
        //设置右上角图形标注名称
        ui.OutputdataShow->graph(0)->setName("Channel 1");
        //传入数据，setData的两个参数类型为double
        ui.OutputdataShow->graph(0)->setData(x1,y1);

        if (configure.channelCount==2)
        {
        QVector<double> x2(OutputChanneltwoData.size()),y2(OutputChanneltwoData.size());

            for(int i=0;i<OutputChanneltwoData.size();i++)
            {
                x2[i] = i * ui.timerTrackBar->value();
                y2[i] = OutputChanneltwoData[i];
            }

        ui.OutputdataShow->addGraph();
        //设置画笔
        ui.OutputdataShow->graph(1)->setPen(QPen(Qt::green));
        //设置右上角图形标注名称
        ui.OutputdataShow->graph(1)->setName("Channel 2");
        //传入数据，setData的两个参数类型为double
        ui.OutputdataShow->graph(1)->setData(x2,y2);
        }

        ui.OutputdataShow->rescaleAxes();

        ui.OutputdataShow->replot();

    }

}

void StaticAO::ButtonOpenDataClicked()
{

    timer->stop();
    ui.OutputdataShow->clearGraphs();
    OutputChanneloneData.clear();
    OutputChanneltwoData.clear();


    QString fileName = QFileDialog::getOpenFileName(this, tr("Excel file"), qApp->applicationDirPath(), tr("Files (*.csv)"));   /// choose a path

    /// Creat failed
    if (fileName.isEmpty())
    {
        return;
    }

    /// Creat successfully
    QFile file(fileName);

    /// Open failed
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "file read", "can't open", QMessageBox::Yes);
        return;
    }

    QStringList lines;   ///行数据

    QTextStream stream_text(&file);    /// 输入流
    while (!stream_text.atEnd())
    {
        lines.push_back(stream_text.readLine());
    }

    for (int j = 0; j < lines.size(); j++)
    {
        QString line = lines.at(j);

        QStringList split = line.split(",");   ///列数据

        if (split.size()>3)
        {
            QMessageBox::warning(this, "file read", "can't open, the number of channel is excess", QMessageBox::Yes);
            return;
        }

        if (j > 0&& j < ui.txtPointCount3->text().toInt())
        {
            dataScaled[0]=split.at(1).toDouble();

            if(channelCount==2)
            {
            dataScaled[1]=split.at(2).toDouble();
            }

            for (int i=0; i<2 ;i++)
            {
                if (dataScaled[i]<0)
                {
                    dataScaled[i]=0;
                }
                if (dataScaled[i]>5)
                {
                    dataScaled[i]=5;
                }
            }

            ErrorCode errorCode = Success;
            errorCode = instantAoCtrl->Write(channelStart, channelCount, dataScaled);

            if (errorCode != Success)
            {
                timer->stop();
                CheckError(errorCode);
            }

            QTime reachTime = QTime::currentTime().addMSecs(ui.txtPointCount2->text().toInt());
            while (QTime::currentTime()<reachTime)
            {
                QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
            }

            /// Show Output data
            OutputChanneloneData.push_back(dataScaled[0]);
            if(channelCount==2)
            {
            OutputChanneltwoData.push_back(dataScaled[1]);
            }

            ui.OutputdataShow->clearGraphs();

            ui.OutputdataShow->legend->setVisible(true);
            //设定右上角图形标注的字体
            ui.OutputdataShow->legend->setFont(QFont("Helvetica", 9));

            QVector<double> x1(OutputChanneloneData.size()),y1(OutputChanneloneData.size());

                for(int i=0;i<OutputChanneloneData.size();i++)
                {
                    x1[i] = i * ui.timerTrackBar->value() ;
                    y1[i] = OutputChanneloneData[i];
                }

                ui.OutputdataShow->addGraph();
                //设置画笔
                ui.OutputdataShow->graph(0)->setPen(QPen(Qt::red));
                //设置右上角图形标注名称
                ui.OutputdataShow->graph(0)->setName("Channel 1");
                //传入数据，setData的两个参数类型为double
                ui.OutputdataShow->graph(0)->setData(x1,y1);

                if(channelCount==2)
                {
                QVector<double> x2(OutputChanneltwoData.size()),y2(OutputChanneltwoData.size());

                    for(int i=0;i<OutputChanneltwoData.size();i++)
                    {
                        x2[i] = i * ui.timerTrackBar->value();
                        y2[i] = OutputChanneltwoData[i];
                    }

                ui.OutputdataShow->addGraph();
                //设置画笔
                ui.OutputdataShow->graph(1)->setPen(QPen(Qt::green));
                //设置右上角图形标注名称
                ui.OutputdataShow->graph(1)->setName("Channel 2");
                //传入数据，setData的两个参数类型为double
                ui.OutputdataShow->graph(1)->setData(x2,y2);
                }

                ui.OutputdataShow->rescaleAxes();

                ui.OutputdataShow->replot();

            }




        }

 file.close();

    }






