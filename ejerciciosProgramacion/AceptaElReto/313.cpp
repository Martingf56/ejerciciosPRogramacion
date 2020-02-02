#include <iostream>
#include <string>
using namespace std;
void casoDePrueba() {
 int banco, ingas;
 cin >> banco >> ingas;
 if (banco + ingas >= 0){
  cout << "SI" << endl;
 }
 else{ cout << "NO" << endl; }
} // casoDePrueba
int main() {
 unsigned int numCasos, i;
 cin >> numCasos;
 for (i = 0; i < numCasos; ++i) {
  casoDePrueba();
 }
 return 0;
}