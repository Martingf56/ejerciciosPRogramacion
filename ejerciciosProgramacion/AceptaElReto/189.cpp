#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000000;
void resuelve(long int v[], int & n) {
 int indi;
 string move;
 cin >> move;
 if (move == "EMBARQUE") {
  int cont = 0;
  int i = 0;
  cin >> indi;
  while (i < n) {
   if (v[i] == indi) 
    ++cont;
   else 
    v[i - cont] = v[i];
   ++i;
  }
  n -= cont;
  cout << n << '\n';
 }
 else if (move == "CONSULTA") {
  cin >> indi;
  cout << v[indi - 1] << '\n';
 }
}
int main() {
 int numps,n;
 long int v[MAX];
 cin >> numps;
 while (numps != 0) {
  for (int i = 0; i < numps; i++) {
   cin >> v[i];
  }
  cin >> n;
  for(int k =0; k < n; ++k)
   resuelve(v, numps);
  cout << "*" << '\n';
  cin >> numps;
 }
 
 return 0;
}