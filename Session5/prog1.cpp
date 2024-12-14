#include <iostream>

using namespace std;

int main () 
{
   int i, j, k = 0;
   for (i = 0; i < 8; i++){
      for (j = 0; j <= i; j++){
         k += i * j;
      }
   }
   cout << k << endl;
   return 0;
}