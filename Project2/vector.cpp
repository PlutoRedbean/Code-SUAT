#include <iostream>

using namespace std;

int dotProduct(int arraySize)
{
    int output = 0;
    int *arrayA = new int[arraySize];
    int *arrayB = new int[arraySize];

    cout << "点乘运算\n";
    cout << "请输入数组A的数:";
    for (int i = 0; i < arraySize; i++) {
        cin >> arrayA[i];
    }
    cout << "请输入数组B的数:";
    for (int i = 0; i < arraySize; i++) {
        cin >> arrayB[i];
    }
    for (int i = 0; i < arraySize; i++) {
        output += arrayA[i] * arrayB[i];
    }

    return output;
    delete [] arrayA;
    delete [] arrayB;
}

void crossProduct(int *arrayA, int *arrayB, int arraySize)
{
    if (arraySize == 3) {
        int *crossResult = new int[arraySize];
        arrayA = new int[arraySize];
        arrayB = new int[arraySize];

        cout << "叉乘运算\n";
        cout << "请输入数组A的数:";
        for (int i = 0; i < arraySize; i++) {
            cin >> arrayA[i];
        }
        cout << "请输入数组B的数:";
        for (int i = 0; i < arraySize; i++) {
            cin >> arrayB[i];
        }

        crossResult[0] = arrayA[1] * arrayB[2] - arrayA[2] * arrayB[1];
        crossResult[1] = arrayA[2] * arrayB[0] - arrayA[0] * arrayB[2];
        crossResult[2] = arrayA[0] * arrayB[1] - arrayA[1] * arrayB[0];

        cout << "叉乘结果:[ " << crossResult[0] << ", " << crossResult[1] << ", " << crossResult[2] << " ]\n";

        delete [] arrayA;
        delete [] arrayB;
        delete [] crossResult;
    } else {
        return;
    }
    
}