#include<iostream>
using namespace std;
const int MAX = 100000;
/*O(n) con un único bucle*/
//{Pre: 0 <= cortezas <= longitud(tamanios)}
int bocadillo(int tamanios[], int cortezas)/* return ret */ {
 int b = cortezas - 1, suma = 0, tapa = cortezas;
 //{I: (0 <= b < cortezas) ^ (suma = Sum i: b < i < cortezas: tamanios[i]) ^ (tabla = max j: (b <= j < cortezas) ^ (tamanios[j] = suma): j + 1 )}
 while (b > 0) {
  suma += tamanios[b];
  --b;
  if (tamanios[b] == suma) tapa = b + 1;
 }
 return tapa;
}
//{Post: suma = Sum i: 0 < i < cortezas: tamanios[i];
//   ret = max j: (0 <= j < cortezas) ^ (tamanios[j] = suma): j + 1 }
void resuelve(int cortezas) {
 int tamanios[MAX];
 for (int i = 0; i < cortezas; ++i) {
  cin >> tamanios[i];
 }
 int tapa = bocadillo(tamanios, cortezas);
 if (tapa == cortezas) cout << "NO\n";
 else cout << "SI " << tapa << '\n';
}
int main() {
 int cortezas;
 cin >> cortezas;
 while (cortezas != 0) {
  resuelve(cortezas);
  cin >> cortezas;
 }
 return 0;
}