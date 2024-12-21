#include <list>
#include <iostream>
using namespace std;

int main() 
{
    list<int> l1;
    for (int i = 0; i < 10; i++) {
        l1.push_back(i);
    }
    list<int>::iterator it = l1.begin();
    while (it != l1.end()) {
        cout << *it << " ";
        it++;
    }
    cout << endl;
    return 0;
}