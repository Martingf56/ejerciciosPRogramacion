#include <iostream>
using namespace std;
int main() {
 int huevos, capacidad,ret;
 cin >> huevos >> capacidad;
 while (huevos != 0 && capacidad != 0) {
  ret = 1;
  ret += huevos / capacidad;
  if (huevos%capacidad==0)
   --ret;
  cout << 10 * ret << '\n';
  cin >> huevos >> capacidad;
 }
 return 0;
}