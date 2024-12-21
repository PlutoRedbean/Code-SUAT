#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
using namespace std;

class DoubleVector {
    double * array;
    size_t n;
public:
    DoubleVector(size_t x);
    ~DoubleVector();
    void print();
};

#endif