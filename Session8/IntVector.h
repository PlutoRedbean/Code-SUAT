#ifndef _INT_VECTOR_H_
#define _INT_VECTOR_H_

#include <iostream>
using namespace std;

class IntVector {
    int * array;
    size_t n;
public:
    IntVector(size_t x);
    ~IntVector();
    void print();
};

#endif