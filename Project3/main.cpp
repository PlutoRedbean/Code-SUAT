#include <iostream>
#include <cstddef>
#include "Array.h"

using namespace std;

int main() 
{
    int aLine, aRow, bLine, bRow;
    while (true) {
        cout << "输入矩阵A的行 列:\n";
        cin >> aLine;
        if (aLine <= 0) {
            break;
        } else {
            cin >> aRow;
            cout << "输入矩阵B的行 列:\n";
            cin >> bLine;
            cin >> bRow;
            double **arrayA, **arrayB;
            arrayA = new double *[aLine];
            cout << "输入矩阵A中的数:\n";
            for (int i = 0; i < aLine; i++) {
                arrayA[i] = new double[aRow];
                for (int j = 0; j < aRow; j++) {
                    cin >> arrayA[i][j];
                }
            }

            arrayB = new double *[bLine];
            cout << "输入矩阵B中的数:\n";
            for (int i = 0; i < bLine; i++) {
                arrayB[i] = new double[bRow];
                for (int j = 0; j < bRow; j++) {
                    cin >> arrayB[i][j];
                }
            }

            double **multiply = arrayMultiply(arrayA, aLine, aRow, arrayB, bLine, bRow);
            if (multiply) {
                cout << "矩阵A x B:\n";
                for (int i = 0; i < aLine; i++) {
                    for (int j = 0; j < bRow; j++) {
                        cout << multiply[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            double **add = arrayAdd(arrayA, aLine, aRow, arrayB, bLine, bRow);
            if (add) {
                cout << "矩阵A + B:\n";
                for (int i = 0; i < aLine; i++) {
                    for (int j = 0; j < bRow; j++) {
                        cout << add[i][j] << " ";
                    }
                    cout << endl;
                }
            }
            double **transpose = arrayTranspose(arrayA, aLine, aRow);
            cout << "矩阵A转置:\n";
            for (int i = 0; i < aRow; i++) {
                for (int j = 0; j < aLine; j++) {
                    cout << transpose[i][j] << " ";
                }
                cout << endl;
            }
            
            for (int i = 0; i < aLine; i++) {
                delete [] arrayA[i];
            }
            delete [] arrayA;

            for (int i = 0; i < bLine; i++) {
                delete [] arrayB[i];
            }
            delete [] arrayB;
            
            delete []multiply;
        }
    }
}
