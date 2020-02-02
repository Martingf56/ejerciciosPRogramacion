#include <iostream>
using namespace std;
void funcionaux() {
 long long int numeros,min,max;
 int i = 1, contmin = 0, contmax = 0;
 cin >> numeros;
 min = numeros;
 max = numeros;
 while (i <( 10 ^ 18) && numeros != 0) {
  if (numeros <= min ) {
   if(numeros==min)
    ++contmin;
   else {
    contmin = 1;
    min = numeros;
   }
  }
  if (numeros >= max) {
   if (numeros == max)
    ++contmax;
   else {
    max = numeros;
    contmax = 1;
   }
  }
  cin >> numeros;
 }
 cout << min << " " << contmin << " " << max << " " << contmax << '\n';
}
int main() {
 int casos;
 cin >> casos;
 for (int i = 0; i < casos; ++i) {
  funcionaux();
 }
 return 0;
}