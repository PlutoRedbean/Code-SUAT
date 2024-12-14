#include <iostream>
#include "Matrix.h"
using namespace std;
int main () 
{
    int N, M, L, K, i, j;
    while (true) {
        cout << "Please input #line and #column of 1st array:\n";
        cin >> N >> M;
        if (N < 0) break;
        Matrix a(N, M);
        cin >> a;
        cout << "Please input #line and #column of 2nd array:\n";
        cin >> L >> K;
        Matrix b(L, K);
        cin >> b;
        Matrix c = a.Add(b);
        cout << "A + B=:\n" << c;
        Matrix d = a.Multiply(b);
        cout << "A * B=:\n" << d;
        cout << "Transpose of 1st array is:\n";
        a.Transpose();
        cout << a;
    }
return 0;
}