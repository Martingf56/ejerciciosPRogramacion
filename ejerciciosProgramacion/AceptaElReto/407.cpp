#include <iostream>
#include <string>
using namespace std;
bool casoDePrueba() {
 int tamp, j, d;
 cin >> tamp >> j >> d;
 if (tamp==0)
  return false;
 else {
  if (tamp >= j + d){ cout << j + d << endl;}
  else if (tamp < j+d ){
   cout << tamp-((j + d) - tamp)<<endl;
  }
  return true;
 }
} // casoDePrueba
int main() {
 while (casoDePrueba()) {
 }
 return 0;
}