#ifndef _X_VECTOR_H_
#define _X_VECTOR_H_

#include <iostream>
using namespace std;

template <class T> class XVector {
    T * array;
    size_t n;
public:
    XVector(size_t x) {
        n = x;
        array = new T[n];
        cout << "Please input" << n << "numbers:\n";
        for (int i = 0; i < n; i++) {
            cin >> array[i];
        }
    }
    ~XVector() {
        delete []array;
    }
    void print() {
        for (int i = 0; i < n; i ++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

#endif