#include <iostream>
#include <string>
using namespace std;
bool recursivo(string clave, int pri, int fin) {
 if (pri >= fin) return true;
 if (clave[pri] == ' ')
  return recursivo(clave, ++pri, fin);
 if (clave[fin] == ' ')
  return recursivo(clave, pri, --fin);
 if (tolower(clave[pri]) != tolower(clave[fin]))
  return false;
 return recursivo(clave, ++pri, --fin);
}
int main() {
 string clave;
 getline(cin, clave);
 while (clave != "XXX")
 {
  if (recursivo(clave, 0, clave.length() - 1)) cout << "SI\n";
  else cout << "NO\n";
  getline(cin, clave);
 }
 return 0;
}