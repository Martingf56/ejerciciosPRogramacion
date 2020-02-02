#include <iostream>
#include <string>
#include <algorithm>
std::string tolower(std::string palabra) {
 int i = 0;
 while (i < palabra.length()) {
  palabra[i] = tolower(palabra[i]);
  ++i;
 }
 return palabra;
}
int main() {
 int casos,i=0;
 std::string palabra1,palabra2,aux;
 std::cin >> casos;
 while (i < casos){
  std::cin >> palabra1 >> aux >> palabra2;
  if (tolower(palabra1) == tolower(palabra2))
   std::cout << "TAUTOLOGIA"<<std::endl;
  else
   std::cout << "NO TAUTOLOGIA"<<std::endl;
  ++i;
 }
 return 0;
}