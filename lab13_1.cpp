#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double data[], int numOfData,double result[]){
    for (int i = 0; i < numOfData; i++)
    {
        result[0] += data[i]/numOfData;
    }
    double sum_sd;
    for (int i = 0; i < numOfData; i++)
    {
        sum_sd += pow(data[i]-result[0],2)/numOfData;
    }
    result[1] = sqrt(sum_sd);
    double gsum = 1;
    for (int i = 0; i < numOfData; i++)
    {
        gsum *= data[i];

    }
    result[2] = pow(gsum,1.0/numOfData);
    double hsum = 0;
    for (int i = 0; i < numOfData; i++)
    {
        hsum += 1.0/data[i];
    }
    result[3] = numOfData/hsum;
    for (int i = 1; i < numOfData; ++i)
    {
        if (data[i] > result[4])
        {
            result[4] = data[i];
        }
    }
    result[5] = data[0];
    for (int i = 1; i < numOfData; ++i) {
        if (data[i] < result[5]) {
            result[5] = data[i];
        }
    }
}