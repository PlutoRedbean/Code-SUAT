#ifndef _DNODE_H_
#define _DNODE_H_
#include <iostream>
using namespace std;

class DNode {
    int key;
    DNode* next;
    DNode* prev;
public:
    DNode (int k);
    friend class DList;
};

#endif
