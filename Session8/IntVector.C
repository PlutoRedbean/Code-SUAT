#include "IntVector.h"
#include <iostream>
using namespace std;

IntVector::IntVector(size_t x) {
    n = x;
    array = new int[n];
    cout << "Please input" << n << "numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
}

IntVector::~IntVector() {
    delete [] array;
}

void IntVector::print() {
    for (int i = 0; i < n; i ++) {
        cout << array[i] << " ";
    }
    cout << endl;
}