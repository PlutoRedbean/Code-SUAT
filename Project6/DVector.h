#ifndef _DVECTOR_H_
#define _DVECTOR_H_
#include <iostream>
using namespace std;

class DVector{
    int* array;
    size_t size;
    size_t start;
    size_t end;
public:
    DVector();
    ~DVector();
    void push_back(int k);
    void push_front(int k);
    int pop_front();
    int pop_end();
    void print_forward();
    void print_backward();
    bool empty();
};
#endif
