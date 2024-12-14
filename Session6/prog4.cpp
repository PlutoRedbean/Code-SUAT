#include <iostream>
#include <fstream>

using namespace std;

int main (int argc, char **argv) 
{
    ifstream myfile (argv[1]);
    if (!myfile.is_open()) {
        return 0;
    }
    int id;
    double msalary, months;
    myfile >> id >> msalary >> months;
    cout << id << " " << msalary << " " << months << endl;
    myfile.close();
    return 0;
}