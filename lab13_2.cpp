#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "Input your brush size and location: ";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 || x != 0 || y != 0);
    return 0;
}

void showImage(const bool A[][M])
{
    cout << "------------------------------------------------------------------------\n";
    for (int i = 0; i < N; i++){
        cout << "|";
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] == true)
            {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "|\n";
    }
    cout << "------------------------------------------------------------------------\n";
}

void updateImage(bool A[][M],int size,int x_pos,int y_pos){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
        {
            if (sqrt(pow(i-x_pos,2)+pow(j-y_pos,2)) <= size-1)
            {
                A[i][j] = true;
            }
            
        }
    }
}