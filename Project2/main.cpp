#include <iostream>
#include "vector.h"

using namespace std;

int main ()
{
   while (true) {
      int num, a[3], b[3], dotResult;
      cout << "请输入数组长度:";
      cin >> num;
      if (num > 0) {
         dotResult = dotProduct(num);
         cout << "点乘结果:" << dotResult << endl;

         crossProduct(a, b, num);
      } else {
         break;
      }
   }
}