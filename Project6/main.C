#include "DList.h"
#include "DVector.h"

int main() {
    DVector a;
    for (int i = 0; i < 40; i++) a.push_back(i);
    for (int i = 0; i < 40; i++) a.push_front(i);
    a.print_forward();
    a.print_backward();
    if (!a.empty()) cout << a.pop_front() << endl;
    if (!a.empty()) cout << a.pop_end() << endl;
    DList b;
    for (int i = 0; i < 40; i++) b.push_back(i);
    for (int i = 0; i < 40; i++) b.push_front(i);
    b.print_forward();
    b.print_backward();
    if (!b.empty()) cout << b.pop_front() << endl;
    if (!b.empty()) cout << b.pop_end() << endl;
    return 0;
}
