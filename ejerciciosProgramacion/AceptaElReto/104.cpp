#include <iostream>
using namespace std;
bool casoDePrueba(int &peso) {
 int pi, di, pd, dd;
 cin >> pi >> di >> pd >> dd;
 if (pi == 0 && di == 0 && pd == 0 && dd == 0) 
  return false;
 
 if (pi == 0) {
  casoDePrueba(peso);
  pi = peso;
 }
 if (pd == 0) {
  pd = casoDePrueba(peso);
  pd = peso;
 }
 if (pi*di == pd * dd)
  peso = pi + pd;
 
 else peso = 0;
 
 return true;
} // casoDePrueba
int main() {
 int peso = 0;
 while (casoDePrueba(peso)) {
  if (peso == 0) {
   cout << "NO" << endl;
  }
  else {
   cout << "SI" << endl;
  }
 }
 return 0;
}