#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <complex>
#include <vector>
#include "configuredialog.h"

using namespace std;

#define PI 3.1415926

class Data_Processing
{
public:
    Data_Processing();   /// Constructor function
    ~Data_Processing();   /// Destructor function
    void initialize();   /// Initialize
    void SaveData(double* ReadDataOnce, ConfigureParameter Configure, int CountOnce);   /// Save data in AllData

    void FFT();   /// FFT
    void IFFT();   /// IFFT
    void Filterlp(int fre , int sam);   /// Filter with low pass
    void Filterhp(int fre , int sam);   /// Filter with high pass


    int d_DataCountOnechannel;   /// The number of data that have been read in one channel
    ConfigureParameter configure;   ///Save the parameter of the device
    int Sampleinverval;
    vector <vector<double>> AllData;   /// Save all data
    vector <vector<complex<double>>> FFTResult;   /// Save the FFTResult
    vector <vector<complex<double>>> FilteredFFT;   /// Save the filtered FFTResult
    vector <vector<double>> FilteredAllData;   /// Save all data that have been filtered
};

#endif /// !DATA_PROCESSING
