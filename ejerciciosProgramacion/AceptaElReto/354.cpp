#include <iostream>
using namespace std;
const int MAX = 200000;
int resuelve(int v[], int n) {
 int i = 1, cont = 1, M = v[0],  max = v[0], min = v[0];
 while (i < n) {
  if (v[i] > max) {
   if (v[i] > M) M = v[i];
  }
  else {
   max = M;
   cont = i + 1;
  }
  ++i;
 }
 return cont;
}
int main() {
 int nump;
 int v[MAX];
 cin >> nump;
 while (nump != 0) {
  for (int i = 0; i < nump; ++i)
   cin >> v[i];
  cout << resuelve(v, nump) << '\n';
  cin >> nump;
 }
 return 0;
}