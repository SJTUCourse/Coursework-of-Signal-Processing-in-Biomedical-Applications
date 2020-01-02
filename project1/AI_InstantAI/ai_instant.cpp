
#include "ai_instant.h"
#include <QPalette>
#include <QtWidgets/QListWidgetItem>
#include <QtWidgets/QMessageBox>

AI_Instant::AI_Instant(QWidget *parent, Qt::WindowFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);
	//Set the minimum and close button of the main frame.
	this->setWindowFlags(Qt::WindowFlags(Qt::WindowSystemMenuHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint));

	//Set the background image for the main frame.
	this->setAutoFillBackground(true);
	QPixmap pixMap(":/AI_Instant/Resources/Background.png");
	QPalette backPalette;
	backPalette.setBrush(this->backgroundRole(), QBrush(pixMap));
	this->setPalette(backPalette);

    ui.sldTimerValue->setRange(5, 1000);
    ui.edtTimerValue->setRange(5, 1000);
    ui.sldTimerValue->setValue(1);
    ui.edtTimerValue->setValue(1);

    /// Set the default of X scaling range
    ui.SetXRangeSlider_X->setRange(1, 1000);
    ui.SetXRangeSpinBox_X->setRange(1, 1000);
    ui.SetXRangeSlider_X->setValue(1);
    ui.SetXRangeSpinBox_X->setValue(1);

    /// Set the default of Y scaling range
    ui.SetYRangeSlider_Y->setRange(1, 1000);
    ui.SetYRangeSpinBox_Y->setRange(1, 1000);
    ui.SetYRangeSlider_Y->setValue(1);
    ui.SetYRangeSpinBox_Y->setValue(1);

    ui.Frequency->setRange(1, 1000);
    ui.Frequency->setValue(10);

	
	// Initialize the scaled data array.
	for (int i = 0; i < 16; i++)
	{
		scaledData[i] = 0;
	}
	instantAiCtrl = NULL;

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(TimerTicked()));

    connect(ui.SetXRangeSpinBox_X, SIGNAL(valueChanged(int)), ui.SetXRangeSlider_X, SLOT(setValue(int)));
    connect(ui.SetXRangeSlider_X, SIGNAL(valueChanged(int)), ui.SetXRangeSpinBox_X, SLOT(setValue(int)));
    connect(ui.SetXRangeSlider_X, SIGNAL(valueChanged(int)), this, SLOT(SetXRangeSliderChanged(int)));

    connect(ui.SetYRangeSpinBox_Y, SIGNAL(valueChanged(int)), ui.SetYRangeSlider_Y, SLOT(setValue(int)));
    connect(ui.SetYRangeSlider_Y, SIGNAL(valueChanged(int)), ui.SetYRangeSpinBox_Y, SLOT(setValue(int)));
    connect(ui.SetYRangeSlider_Y, SIGNAL(valueChanged(int)), this, SLOT(SetYRangeSliderChanged(int)));

    connect(ui.sldTimerValue, SIGNAL(valueChanged(int)), ui.edtTimerValue, SLOT(setValue(int)));
    connect(ui.edtTimerValue, SIGNAL(valueChanged(int)), ui.sldTimerValue, SLOT(setValue(int)));
	connect(ui.sldTimerValue, SIGNAL(valueChanged(int)), this, SLOT(SliderValueChanged(int)));


	connect(ui.btnConfigure, SIGNAL(clicked()), this, SLOT(ButtonConfigureClicked()));
	connect(ui.btnStart, SIGNAL(clicked()), this, SLOT(ButtonStartClicked()));
	connect(ui.btnPause, SIGNAL(clicked()), this, SLOT(ButttonPauseClicked()));
	connect(ui.btnStop, SIGNAL(clicked()), this, SLOT(ButtonStopClicked()));
    connect(ui.btnSaveData, SIGNAL(clicked()), this, SLOT(ButtonSaveDataClicked()));   /// Save data as CSV
    connect(ui.btnOpenData, SIGNAL(clicked()), this, SLOT(ButtonOpenDataClicked()));   /// Open data as CSV

    connect(ui.FFTChoose, SIGNAL(currentIndexChanged(int)), this, SLOT(FFTShowFunction()));
    connect(ui.FilterChoose, SIGNAL(currentIndexChanged(int)), this, SLOT(FFTShowFunction()));
    connect(ui.Frequency, SIGNAL(valueChanged(int)), this, SLOT(FFTShowFunction()));

	graph = new SimpleGraph(ui.graphFrame);
	graph->setFixedSize(ui.graphFrame->size());
    ui.graphFrame->setMouseTracking(true);
    ui.FFTChoose->setCurrentIndex(0);
}

AI_Instant::~AI_Instant()
{
	if (instantAiCtrl != NULL)
	{
		instantAiCtrl->Dispose();
	}
}

void AI_Instant::Initialize()
{
	this->setWindowTitle(tr("Instant AI - Run(") + configure.deviceName + tr(")"));
	
	ConfigureDevice();
	ConfigureGraph();
    Data.initialize();   /// initialize
    Data.Sampleinverval=ui.sldTimerValue->value();

	//Initialize the list.
	ui.listWidget->clear();
	QListWidgetItem *item = NULL; 
	for (int i = 0; i < configure.channelCount; i++)
	{
		item = new QListWidgetItem(tr("0.0000"), ui.listWidget);
		item->setBackgroundColor(SimpleGraph::lineColor[i]);
		item->setSizeHint(QSize(59, 24));
		item->setTextAlignment(Qt::AlignCenter);
	}

	ui.btnConfigure->setEnabled(true);
	ui.btnStart->setEnabled(true);
	ui.btnPause->setEnabled(false);
	ui.btnStop->setEnabled(false);
	ui.sldTimerValue->setEnabled(true);
}

void AI_Instant::ConfigureDevice()
{
	if (instantAiCtrl == NULL)
	{
      instantAiCtrl = InstantAiCtrl::Create();
	}

    std::wstring description = configure.deviceName.toStdWString();
    DeviceInformation selected(description.c_str());

    ErrorCode errorCode = instantAiCtrl->setSelectedDevice(selected);
	CheckError(errorCode);
	errorCode = instantAiCtrl->LoadProfile(configure.profilePath);
	CheckError(errorCode);

	//Get channel max number. set value range for every channel.
	Array<AiChannel> *channels = instantAiCtrl->getChannels();
	for (int i = 0; i < channels->getCount(); i++)
	{
		channels->getItem(i).setValueRange(configure.valueRange);
	}
}

void AI_Instant::ConfigureGraph()
{
	TimeUnit timeUnit = Second;
	QString	xRanges[2] = {tr("")};
    double SetXRange = ui.SetXRangeSlider_X->value();
    graph->m_SetXRange = SetXRange;
    graph->GetXCordRange(xRanges, 10, 0, timeUnit, SetXRange);   /// Default 0s-10s

	ui.lblXCoordinateStart->setText(xRanges[1]);
	ui.lblXCoordinateEnd->setText(xRanges[0]);

	ValueUnit unit;
	MathInterval rangeY;
	QString yRanges[3] = {tr("")};
	ErrorCode errorCode = AdxGetValueRangeInformation(configure.valueRange, 0, NULL, &rangeY, &unit);
	CheckError(errorCode);

    double SetYRange = ui.SetYRangeSlider_Y->value();
    graph->m_SetYRange = SetYRange;

    graph->GetYCordRange(yRanges, rangeY.Max, rangeY.Min, unit, SetYRange);
	ui.lblYCoordinateMax->setText(yRanges[0]);
	ui.lblYCoordinateMin->setText(yRanges[1]);
	ui.lblYCoordinateMid->setText(yRanges[2]);

	if (Milliampere == unit || Millivolt == unit)
	{
		rangeY.Max /= 1000;
		rangeY.Min /= 1000;
	}
	graph->m_xCordTimeDiv = 1000;
	graph->m_yCordRangeMax = rangeY.Max;
	graph->m_yCordRangeMin = rangeY.Min;
	graph->Clear();
}

void AI_Instant::CheckError(ErrorCode errorCode)
{
    if (BioFailed(errorCode))
	{
		QString message = tr("Sorry, there are some errors occurred, Error Code: 0x") +
			QString::number(errorCode, 16).right(8).toUpper();
		QMessageBox::information(this, "Warning Information", message);
	}
}

void AI_Instant::TimerTicked()
{
	ErrorCode errorCode = Success;
    errorCode = instantAiCtrl->Read(configure.channelStart, configure.channelCount, scaledData);
	CheckError(errorCode);
	if (errorCode != Success)
	{
		return;
	}

	int dataCylic = ui.sldTimerValue->value();
	graph->Chart(scaledData, configure.channelCount, 1, 1.0 * dataCylic / 1000);
    Data.SaveData(scaledData, configure, 1);   /// Save the data
	RefreshList();
}

void AI_Instant::RefreshList()
{
	QListWidgetItem *item;
	QString dataStr = tr("0.0000");
	QString str = tr("");
	for(int i = 0; i < ui.listWidget->count(); i++)
	{
		item = ui.listWidget->item(i);
		str.sprintf("%.4f", scaledData[i]);
		dataStr = str;
		if (str.length() > 7)
		{
			dataStr = str.left(7);
		}
		item->setText(dataStr);
	}
}

void AI_Instant::SliderValueChanged(int value)
{ 
	timer->setInterval(ui.sldTimerValue->value());
	graph->Clear();
    Data.initialize();
    Data.Sampleinverval=ui.sldTimerValue->value();
}

void AI_Instant::ButtonConfigureClicked()
{
	timer->stop();
	graph->Clear();

	int dialogResult = configDialog->exec();
	if (dialogResult == QDialog::Accepted)
	{
		configure = configDialog->GetConfigureParameter();
		Initialize();
	}

    Data.initialize();
    Data.Sampleinverval=ui.sldTimerValue->value();
}

void AI_Instant::ButtonStartClicked()
{
	int dataCylic = ui.sldTimerValue->value();
	timer->start(dataCylic);

    ui.FFTChoose->clear();

    for (int i = 0; i < configure.channelCount; i++)
    {
        ui.FFTChoose->addItem(QString("%1").arg(configure.channelStart+i));
    }
	
	ui.btnConfigure->setEnabled(false);
	ui.btnStart->setEnabled(false);
	ui.btnPause->setEnabled(true);
	ui.btnStop->setEnabled(true);
}

void AI_Instant::ButttonPauseClicked()
{
	timer->stop();

	ui.btnPause->setEnabled(false);
	ui.btnStart->setEnabled(true);
	ui.btnStop->setEnabled(true);
    FFTShowFunction();
}

void AI_Instant::ButtonStopClicked()
{
	timer->stop();
	graph->Clear();

	ui.btnConfigure->setEnabled(true);
	ui.btnPause->setEnabled(false);
	ui.btnStart->setEnabled(true);
	ui.btnStop->setEnabled(false);

    Data.initialize();
    Data.Sampleinverval=ui.sldTimerValue->value();
}

void AI_Instant::SetXRangeSliderChanged(int value)
{
    ConfigureGraph();   /// Configure the Graph
}

void AI_Instant::SetYRangeSliderChanged(int value)
{
    ConfigureGraph();   /// Configure the Graph
}

/// Get the coordinate when move the mouse to the graghframe
void AI_Instant::mouseMoveEvent(QMouseEvent* event)
{
    QPoint MouseCoordinate = event-> globalPos();
    MouseCoordinate = ui.graphFrame->mapFromGlobal(MouseCoordinate);

    ///MouseCoordinate.setX(MouseCoordinate.x() / (ui.graphFrame->rect().width()) * 10);
    double rangeMax = 10 / graph->m_SetXRange;
    while (rangeMax < 1)
    {
        rangeMax *= 1000;
    }

    double x = double(MouseCoordinate.x()) / (ui.graphFrame->rect().width()) * rangeMax;
    ValueUnit unit;   /// Unit of voltage
    MathInterval rangeY;
    ErrorCode errorCode = AdxGetValueRangeInformation(configure.valueRange, 0, NULL, &rangeY, &unit);
    CheckError(errorCode);
    ///MouseCoordinate.setY(rangeY.Max - MouseCoordinate.y() / (ui.graphFrame->rect().height()) * (rangeY.Max - rangeY.Min));
    double rangeMax1 = rangeY.Max / graph->m_SetYRange;
    double rangeMin1 = rangeY.Min / graph->m_SetYRange;

    while (rangeMax1 < 1)
    {
        rangeMax1 *= 1000;
        rangeMin1 *= 1000;
    }
    double y = rangeMax1 - double(MouseCoordinate.y()) / (ui.graphFrame->rect().height()) * (rangeMax1 - rangeMin1);
    QString str;
    str = QString("%1 , %2").arg(x).arg(y);

    ui.MouseCoordinate->setText(str);
};

/// Save the data
void AI_Instant::ButtonSaveDataClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath(), tr("Files (*.csv)"));   /// choose a path

    /// Creat failed
    if (fileName.isEmpty())
    {
        return;
    }

    /// Creat successfully
    QFile file(fileName);

    /// Open failed
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::warning(this, "file write", "can't open", QMessageBox::Yes);
        return;
    }

    /// Open successfully
    QTextStream out(&file);    // 输入流

    /// Output title bar
    out << "Order,";
    for (int i = 0; i < Data.configure.channelCount; i++)
    {
        out << (i + Data.configure.channelStart) << ",";
    }

    out << Data.Sampleinverval;

    /// Output the data
    for (int i = 0; i < Data.d_DataCountOnechannel; i++)
    {
        out << '\n';

        out << i << ',';

        for (int j = 0; j < Data.configure.channelCount; j++)
        {
            if(j<Data.configure.channelCount-1)
            {
                out << Data.AllData[j][i] << ',';
            }

            else
            {
                out << Data.AllData[j][i];
            }
        }


    }

    file.close();
}

/// Open the data
void AI_Instant::ButtonOpenDataClicked()
{
    Data.initialize();
    ui.btnStart->setEnabled(false);
    ui.btnStop->setEnabled(true);

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

    /// Open successfully
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

        if (j == 0)
        {
            Data.configure.channelStart = split.at(1).toInt();
            Data.configure.channelCount = split.at(split.size() - 2).toInt() - Data.configure.channelStart + 1;
            Data.Sampleinverval=split.at(split.size() - 1).toInt();
        }

        else
        {
            for (int col = 1; col < split.size(); col++)
            {
                Data.AllData[col - 1].push_back(split.at(col).toDouble());
            }  
        }
    }

    Data.d_DataCountOnechannel=lines.size()-1;

    ui.FFTChoose->clear();

    for (int i = 0; i < Data.configure.channelCount; i++)
    {
        ui.FFTChoose->addItem(QString("%1").arg(Data.configure.channelStart+i));
    }
    file.close();

    FFTShowFunction();

}

void AI_Instant::FFTShowFunction()
{
    ui.OriginShow2->clearGraphs();

    ui.OriginShow2->legend->setVisible(true);
    //设定右上角图形标注的字体
    ui.OriginShow2->legend->setFont(QFont("Helvetica", 9));

    QVector<double> x3(Data.AllData[0].size()),y3(Data.AllData[0].size());

        for(int i=0;i<Data.AllData[0].size();i++)
        {
            x3[i] = i*Data.Sampleinverval;
            y3[i] = Data.AllData[ui.FFTChoose->currentText().toInt()-Data.configure.channelStart][i];
        }

        ui.OriginShow2->addGraph();
        //设置画笔
        ui.OriginShow2->graph(0)->setPen(QPen(Qt::blue));
        //设置画刷,曲线和X轴围成面积的颜色
         ///ui.FFTShow->graph(0)->setBrush(QBrush(QColor(255,255,0)));
        //设置右上角图形标注名称
        ui.OriginShow2->graph(0)->setName("曲线");
        //传入数据，setData的两个参数类型为double
        ui.OriginShow2->graph(0)->setData(x3,y3);

        ui.OriginShow2->rescaleAxes();

        ui.OriginShow2->replot();
    //设定右上角图形标注可见
    //设置X轴坐标范围
          Data.FFT();

           ui.FFTShow->clearGraphs();

           ui.FFTShow->legend->setVisible(true);
           //设定右上角图形标注的字体
           ui.FFTShow->legend->setFont(QFont("Helvetica", 9));

           QVector<double> x(Data.FFTResult[0].size()),y(Data.FFTResult[0].size());

               for(int i=0;i<Data.FFTResult[0].size();i++)
               {
                   x[i] = i*(1000/Data.Sampleinverval)/Data.d_DataCountOnechannel;
                   y[i] = abs(Data.FFTResult[ui.FFTChoose->currentText().toInt()-Data.configure.channelStart][i]);
               }



               ui.FFTShow->addGraph();
               //设置画笔
               ui.FFTShow->graph(0)->setPen(QPen(Qt::blue));
               //设置画刷,曲线和X轴围成面积的颜色
                ///ui.FFTShow->graph(0)->setBrush(QBrush(QColor(255,255,0)));
               //设置右上角图形标注名称
               ui.FFTShow->graph(0)->setName("曲线");
               //传入数据，setData的两个参数类型为double
               ui.FFTShow->graph(0)->setData(x,y);

               ui.FFTShow->rescaleAxes();

               ui.FFTShow->replot();


                /// FilteredFFT Show

               if(ui.FilterChoose->currentIndex()==0)
               {

                   Data.Filterlp(ui.Frequency->value(),Data.Sampleinverval);

               }

               if(ui.FilterChoose->currentIndex()==1)
               {

                   Data.Filterhp(ui.Frequency->value(),Data.Sampleinverval);

               }

               ui.FilterFFTShow->clearGraphs();

               ui.FilterFFTShow->legend->setVisible(true);
               //设定右上角图形标注的字体
               ui.FilterFFTShow->legend->setFont(QFont("Helvetica", 9));

               QVector<double> x1(Data.FilteredFFT[0].size()),y1(Data.FilteredFFT[0].size());

                   for(int i=0;i<Data.FilteredFFT[0].size();i++)
                   {
                       x1[i] = i*(1000/Data.Sampleinverval)/Data.d_DataCountOnechannel;
                       y1[i] = abs(Data.FilteredFFT[ui.FFTChoose->currentText().toInt()-Data.configure.channelStart][i]);
                   }



                   ui.FilterFFTShow->addGraph();
                   //设置画笔
                   ui.FilterFFTShow->graph(0)->setPen(QPen(Qt::red));
                   //设置画刷,曲线和X轴围成面积的颜色
                    ///ui.FFTShow->graph(0)->setBrush(QBrush(QColor(255,255,0)));
                   //设置右上角图形标注名称
                   ui.FilterFFTShow->graph(0)->setName("曲线");
                   //传入数据，setData的两个参数类型为double
                   ui.FilterFFTShow->graph(0)->setData(x1,y1);

                   ui.FilterFFTShow->rescaleAxes();

                   ui.FilterFFTShow->replot();


                   ///Origin Show
                   Data.IFFT();

                   ui.OriginShow->clearGraphs();

                   ui.OriginShow->legend->setVisible(true);
                   //设定右上角图形标注的字体
                   ui.OriginShow->legend->setFont(QFont("Helvetica", 9));

                   QVector<double> x2(Data.FilteredAllData[0].size()),y2(Data.FilteredAllData[0].size());

                       for(int i=0;i<Data.FilteredAllData[0].size();i++)
                       {
                           x2[i] = i*Data.Sampleinverval;
                           y2[i] = Data.FilteredAllData[ui.FFTChoose->currentText().toInt()-Data.configure.channelStart][i];
                       }



                       ui.OriginShow->addGraph();
                       //设置画笔
                       ui.OriginShow->graph(0)->setPen(QPen(Qt::red));
                       //设置画刷,曲线和X轴围成面积的颜色
                        ///ui.FFTShow->graph(0)->setBrush(QBrush(QColor(255,255,0)));
                       //设置右上角图形标注名称
                       ui.OriginShow->graph(0)->setName("曲线");
                       //传入数据，setData的两个参数类型为double
                       ui.OriginShow->graph(0)->setData(x2,y2);

                       ui.OriginShow->rescaleAxes();

                       ui.OriginShow->replot();

}
