#include <iostream>
using namespace std;
int Suma(int n) {
 if (n < 10) {
  cout << n;
  return n;
 }
 int aux = n % 10 + Suma(n / 10);
 cout << " + " << n % 10 ;
 return aux;
}
int main() {
 int n;
 cin >> n;
 while (n >= 0) {
  cout << " = " << Suma(n) << '\n';
  cin >> n;
 }
 return 0;
}