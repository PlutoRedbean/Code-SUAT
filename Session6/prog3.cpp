#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv) 
{
    string line;
    ifstream myfile (argv[1]);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            cout << line << endl;
        }
        myfile.close();
    } else {
        cout << "Unable";
    }
    return 0;
}