#include "DVector.h"

DVector::DVector()
{
    size = 16;
    start = 4;
    end = 3;
    array = new int[size];
}

DVector::~DVector()
{
    delete []array;
}

void DVector::push_back(int k)        //增加一个新的元素在DVector尾端
{
    if (end < start) {
        end = start;
        array[end] = k;
        return;
    }
    if (end < size - 1) {
        array[++end] = k;
        return;
    } else {
        int* tmp = new int[size];
        size_t tmp_size = size;
        for (size_t i = 0; i < size; i++) {
            tmp[i] = array[i];
        }
        delete []array;
        size += size;
        array = new int[size + size];
        for (size_t i = 0; i < tmp_size; i++) {
            array[i] = tmp[i];
        }
        array[++end] = k;
        delete []tmp;
        return;
    }
}

void DVector::push_front(int k)        //增加一个新的元素在DVector头端
{
    if (end < start) {
        end = start;
        array[end] = k;
        return;
    }
    if (start > 0) {
        array[--start] = k;
        return;
    } else {
        int* tmp = new int[size];
        size_t tmp_size = size;
        for (size_t i = 0; i < size; i++) {    //复制DVector
            tmp[i] = array[i];
        }
        delete []array;
        size += size;
        start += tmp_size;
        end += tmp_size;
        array = new int[size + size];
        for (size_t i = 0; i < tmp_size; i++) {
            array[tmp_size + i] = tmp[i];
        }
        array[--start] = k;
        delete []tmp;
        return;
    }
}

int DVector::pop_front()      //删除DVector第一个元素
{
    // ++start;
    // return array[--start];
    return array[start++];
}

int DVector::pop_end()        //删除DVector最后一个元素
{
    // --end;
    // return array[++end];
    return array[end--];
}

void DVector::print_forward()     //从头开始打印
{
    for (size_t i = start; i <= end; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

void DVector::print_backward()    //从尾开始打印
{
    for (size_t i = end; i >= start; i--) {
        cout << array[i] << " ";
    }
    cout << endl;
    return;
}

bool DVector::empty()
{
    return end < start;
}
