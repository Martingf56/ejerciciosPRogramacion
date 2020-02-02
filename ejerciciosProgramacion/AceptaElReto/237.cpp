#include <iostream>
using namespace std;
bool resuelve(long long n,int tam) {
 if (n < 10)
  return n % tam == 0;
 return n % tam == 0? resuelve(n / 10, tam - 1) : false;
}
int calcnumDigitos(long long n) {
 int i = 1;
 while (n >= 10) {
  n /= 10;
  ++i;
 }
 return i;
}
int main() {
 long long num;
 cin >> num;
 while (cin) {
  if (resuelve(num, calcnumDigitos(num)))
   cout << "POLIDIVISIBLE\n";
  else cout << "NO POLIDIVISIBLE\n";
  cin >> num;
 }
 return 0;
}