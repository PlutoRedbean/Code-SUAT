#include <iostream>
#include <math.h>
using namespace std;

int myInput(){

}

int main()
{
    int int1 = 11;
    int int2 = 2, ave;
    double average;
    ave = int1 / int2;
    cout << ave << endl;
    average = int1 / (int2 + 0.0);
    cout << average << endl;
    ave *= 2;
    cout << ave << endl;
    ave = int1 % 3;
    cout << ave << endl;
    ave = (int1 + int2) * ave;
    cout << ave << endl;
    int1 = int2 = ave = 2;
    float test = 2;
    cout << pow(test, 3) << endl;

    return 0;
}