#include "DList.h"

DList::DList()
{
    head = nullptr;
    tail = nullptr;
}

DList::~DList()
{
    DNode* tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

void DList::push_back(int k)        //增加一个新的元素在DList尾端
{
    if (head == nullptr) {
        head = tail = new DNode(k);
        return;
    }
    DNode* newNode = new DNode(k);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
    return;
}

void DList::push_front(int k)       //增加一个新的元素在DList头端
{
    if (head == nullptr) {
        head = tail = new DNode(k);
        return;
    }
    DNode* newNode = new DNode(k);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;
}

int DList::pop_front()      //删除DList第一个元素
{
    int value = head->key;
    DNode* tmp = head->next;
    delete head;
    head = tmp;
    head->prev = nullptr;
    return value;
}

int DList::pop_end()        //删除DList最后一个元素
{
    int value = tail->key;
    DNode* tmp = tail->prev;
    delete tail;
    tail = tmp;
    tail->next = nullptr;
    return value;
}

void DList::print_forward()     //从头开始打印
{
    DNode* tmp = head;
    while (tmp != nullptr) {
        cout << tmp->key << " ";
        tmp = tmp->next;
    }
    cout << endl;
    return;
}

void DList::print_backward()    //从尾开始打印
{
    DNode* tmp = tail;
    while (tmp != nullptr) {
        cout << tmp->key << " ";
        tmp = tmp->prev;
    }
    cout << endl;
    return;
}

bool DList::empty()
{
    return head == nullptr;
}
