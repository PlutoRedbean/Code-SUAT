#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "输入整数年龄：";
    cin >> age;

    if(age < 0){
        cout << "输入不合法\n";
    }else if(age <= 12 && age >= 0){
        cout << "小孩" << endl;
    }else if(age >= 13 && age <= 19){
        cout << "青年" << endl;
    }else if(age >= 20 && age <= 30){
        cout << "年轻人" << endl;
    }else if(age >= 31 && age <= 50){
        cout << "中年人" << endl;
    }else if(age >= 51 && age <= 120){
        cout << "老年人" << endl;
    }else{
        cout << "Impossible\n";
    }
}