#include <iostream>
#include "Matrix.hpp"

using namespace std;

int main () 
{
    int a_l, a_c, b_l, b_c, c_l, c_c, d_l, d_c, e_l, e_c;
/*----------------------------------------------------------------------*/
    cout << "输入矩阵 A、B 以进行计算测试\n";
    cout << "请设置矩阵 A 的横行,竖列:\n";
    cin >> a_l >> a_c;
    Matrix a(a_l, a_c);
    cin >> a;
    cout << "请设置矩阵 B 的横行,竖列:\n";
    cin >> b_l >> b_c;
    Matrix b(b_l, b_c);
    cin >> b;
    cout << endl;

    cout << "a + b:" << endl;
    cout << a + b << endl;

    cout << "a * b:" << endl;
    cout << a * b << endl;
/*----------------------------------------------------------------------*/
    cout << "输入矩阵 C、D 以进行操作测试\n";
    cout << "输入矩阵 C 的横行,竖列:\n";
    cin >> c_l >> c_c;
    Matrix c(c_l, c_c);
    cin >> c;
    cout << "输入矩阵 D 的横行,竖列:\n";
    cin >> d_l >> d_c;
    Matrix d(d_l, d_c);
    cin >> d;
    cout << endl;

    cout << "c = d:" << endl;
    c = d;
    cout << "c:" << endl;
    cout << c << endl;

    cout << "c++:" << endl;
    cout << c++ << endl;
    cout << "c:" << endl;
    cout << c << endl;

    cout << "++c:" << endl;
    cout << ++c << endl;
/*----------------------------------------------------------------------*/
    cout << "目前的矩阵 C :" << endl;
    cout << c;
    cout << "输入矩阵 E 来与矩阵 C 进行比较测试\n";
    cout << "输入矩阵 E 的横行,竖列:\n";
    cin >> e_l >> e_c;
    Matrix e(e_l, e_c);
    cin >> e;
    if (e == c) {
        cout << "e == c : true" << endl;
        cout << "e != c : false" << endl;
    } else if (e != c) {
        cout << "e == c : false" << endl;
        cout << "e != c : true" << endl;
    }
return 0;
}