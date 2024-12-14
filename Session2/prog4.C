#include <iostream>
#include <math.h>
using namespace std;

float in1, in2, in3, ave, square, standard;

int main()
{
    cout << "请输入浮点数：\n";
    cin >> in1;
    cout << "请输入浮点数：\n";
    cin >> in2;
    cout << "请输入浮点数：\n";
    cin >> in3;

    ave = (in1 + in2 + in3) / 3;
    square = (
        (pow((in1 - ave), 2)) + 
        (pow((in2 - ave), 2)) + 
        (pow((in3 - ave), 2))
        )/3;
    standard = pow(square, 0.5);
    cout << "平均数：" << ave << "\n方差：" << square << "\n标准差:" << standard;
    return 0;
}