#include <iostream>
#include <string>
using namespace std;
void resuelve() {
 string nombre;
 cin >> nombre >> nombre;
 cout << "Hola, " << nombre << ".\n";
}
int main() {
 int casos;
 cin >> casos;
 for (int i = 0; i < casos; ++i)
  resuelve();
 return 0;
}