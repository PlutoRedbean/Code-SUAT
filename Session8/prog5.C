#include <functional>
#include <iostream>
#include <list>
using namespace std;

ostream & operator<<(ostream & os, const list<int>& l1)
{
    for (list<int>::const_iterator it = l1.begin(); it != l1.end(); it++) {
        cout << *it << " ";
    }
    return os;
}

int main() 
{
    list<int> li;
    int temp;
    cout << "Please input 10 int:\n";
    for (int i = 0; i < 10; i++) {
        cin >> temp;
        li.push_back(temp);
    }
    cout << "initially: " << li << '\n';

    li.sort();
    cout << "ascending: " << li << endl;

    li.sort(greater<int>());
    cout << "descending: " << li << endl;
    return 0;
}