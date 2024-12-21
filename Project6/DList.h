#include "DNode.h"
#include <iostream>
using namespace std;

class DList {
    DNode* head;
    DNode* tail;
public:
    DList();
    ~DList();
    void push_back(int k);
    void push_front(int k);
    int pop_front();
    int pop_end();
    void print_forward();
    void print_backward();
    bool empty();
};
