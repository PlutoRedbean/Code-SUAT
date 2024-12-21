#include "XVector.h"
#include <iostream>
using namespace std;

int main() 
{
    XVector<int> v1(4);
    v1.print();
    XVector<double> v2(4);
    v2.print();
    return 0;
}