#include "DoubleVector.h"
#include <iostream>
using namespace std;

DoubleVector::DoubleVector(size_t x) {
    n = x;
    array = new double[n];
    cout << "Please input" << n << "numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
}

DoubleVector::~DoubleVector() {
    delete [] array;
}

void DoubleVector::print() {
    for (int i = 0; i < n; i ++) {
        cout << array[i] << " ";
    }
    cout << endl;
}