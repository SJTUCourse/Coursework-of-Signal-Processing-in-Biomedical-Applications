#include"data_processing.h"
#include<cstring>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>

/// Constructor function
Data_Processing::Data_Processing()
{
    AllData.resize(16);
    configure.channelCount=0;
    d_DataCountOnechannel = 0;
}

/// Destructor function
Data_Processing::~Data_Processing()
{

}

/// Initialize
void Data_Processing::initialize()
{
    AllData.resize(16);
    FFTResult.resize(16);
    FilteredFFT.resize(16);
    FilteredAllData.resize(16);
    configure.channelCount = 0;
    configure.channelStart = 0;
    d_DataCountOnechannel = 0;
    Sampleinverval = 0 ;

    for (int i = 0; i < 16; i++)
    {
        AllData[i].clear();
        FFTResult[i].clear();
        FilteredFFT[i].clear();
        FilteredAllData[i].clear();
    }
}

/// Save data in AllData
void Data_Processing::SaveData(double* ReadDataOnce, ConfigureParameter configureget, int CountOnce)
{

    for (int i = 0; i < configureget.channelCount; i++)
    {
        AllData[i].push_back(ReadDataOnce[i]);
    }

    configure = configureget;
    d_DataCountOnechannel += CountOnce;

}

/// FFT using formula method
void Data_Processing::FFT()
{
    /// Initialize
    for (int i=0 ; i<16; i++ )
    {
        FFTResult[i].clear();
    }

    for (int i = 0; i < configure.channelCount; i++)
    {
        for (int j = 0; j < d_DataCountOnechannel; j++)
        {
            complex<double> Buffer = 0;
            complex<double> wn = 0;

            for (int k = 0; k < d_DataCountOnechannel; k++)
            {
                wn = (complex<double>(cos(2.0 * PI / d_DataCountOnechannel * j * k), sin(-1 * 2.0 * PI / d_DataCountOnechannel * j * k))) * AllData[i][k];
                Buffer +=  wn;
            }

            Buffer=Buffer/double(d_DataCountOnechannel);
            FFTResult[i].push_back(Buffer);

        }
    }
}

/// IFFT using formula method
void Data_Processing::IFFT()
{
    FilteredAllData.resize(configure.channelCount);
    for (int i=0 ; i<configure.channelCount; i++ )
    {
        FilteredAllData[i].clear();
    }

    for (int i = 0; i < configure.channelCount; i++)
    {
        for (int j = 0; j < d_DataCountOnechannel; j++)
        {

            complex<double> Buffer = 0;
            complex<double> wn = 0;

            for (int k = 0; k < d_DataCountOnechannel/2; k++)
            {
                wn = (complex<double>(cos(2.0 * PI / d_DataCountOnechannel * j * k), sin(1 * 2.0 * PI / d_DataCountOnechannel * j * k))) * FilteredFFT[i][k];
                Buffer +=  wn;
            }
            Buffer=Buffer;
            FilteredAllData[i].push_back(2*Buffer.real());

        }
    }
}

/// Filter with low pass
void Data_Processing::Filterlp(int fre, int sam)
{
    FilteredFFT.resize(configure.channelCount);
    for (int i=0 ; i<configure.channelCount; i++ )
    {
        FilteredFFT[i].clear();
    }

    for (int i = 0; i < configure.channelCount; i++)
    {
        for (int j = 0; j < d_DataCountOnechannel/2; j++)
        {

            double Filterco = (1 / (1 + ((j*(1000.0/sam)/d_DataCountOnechannel)/fre) * ((j*(1000.0/sam)/d_DataCountOnechannel)/fre)));   /// Low pass filter
            FilteredFFT[i].push_back( FFTResult[i][j]*Filterco ) ;

        }

        for (int j = d_DataCountOnechannel/2; j < d_DataCountOnechannel; j++)
        {

            if(d_DataCountOnechannel-j>FilteredFFT[i].size()-1)
            {
                  FilteredFFT[i].push_back( FilteredFFT[i][FilteredFFT[i].size()-1] ) ;
            }


            else
            {
                FilteredFFT[i].push_back(FilteredFFT[i][ d_DataCountOnechannel-j] ) ;
            }


        }


    }
}

/// Filter with high pass
void Data_Processing::Filterhp(int fre , int sam)
{
    FilteredFFT.resize(configure.channelCount);
    for (int i=0 ; i<configure.channelCount; i++ )
    {
        FilteredFFT[i].clear();
    }

    for (int i = 0; i < configure.channelCount; i++)
    {
        for (int j = 0; j < d_DataCountOnechannel/2; j++)
        {
            double Filterco = (1 / (1 + fre/((j*(1000.0/sam)/d_DataCountOnechannel)+1) * fre/((j*(1000.0/sam)/d_DataCountOnechannel)+1)));   /// High pass filter
            FilteredFFT[i].push_back( FFTResult[i][j]*Filterco);
        }

        for (int j = d_DataCountOnechannel/2; j < d_DataCountOnechannel; j++)
        {

            if(d_DataCountOnechannel-j>FilteredFFT[i].size()-1)
            {
                  FilteredFFT[i].push_back( FilteredFFT[i][FilteredFFT[i].size()-1] ) ;
            }

            else
            {
                FilteredFFT[i].push_back(FilteredFFT[i][ d_DataCountOnechannel-j] ) ;
            }


        }


    }
}


