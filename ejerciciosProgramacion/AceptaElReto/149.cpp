#include <iostream>
using namespace std;
int resuelve(int n) /*return ret*/ {
 int max,toro, i = 1;
 cin >> toro;
 max = toro;
 while (i < n) {
  cin >> toro;
  if (max < toro)
   max = toro;
  ++i;
 }
 return max;
}
int main() {
 int  toros, v[100000], cont;
 cin >> toros;
 while (cin) {
  cout << resuelve(toros) << '\n';
  cin >> toros;
 }
 return 0;
}