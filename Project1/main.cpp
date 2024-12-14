#include <iostream>
using namespace std;

int main()
{
    int N, arrayA[10], arrayB[10], output;
    output = 0;
    while (true) {
        cout << "请输入N:";
        cin >> N;
        if (N <= 10 && N > 0) {
            cout << "请输入数组A:";
            for (int i = 0; i < N; i++) {
                cin >> arrayA[i];
            }
            cout << "请输入数组B:";
            for (int i = 0; i < N; i++) {
                cin >> arrayB[i];
            }
            
            for (int i = 0; i < N; i++) {
                output += output + arrayA[i] * arrayB[i];
                // cout << output << endl;
            }
            cout << output << endl;
            output = 0;
        } else if (N > 10) {
            cout << "N is too large\n";
        } else {
            cout << "Invalid input. Program end.\n";
            break;
        }
    }
    return 0;
}