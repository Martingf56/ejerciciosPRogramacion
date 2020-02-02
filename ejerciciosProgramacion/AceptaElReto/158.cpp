#include <iostream>
using namespace std;
void resuelve(int n) {
 int sup = 0, sdown = 0,numact,numant;
 int i = 1;
 cin >> numact;
 numant = numact;
 while (i < n) {
  cin >> numact;
  if (numant < numact) ++sup;
  else if (numant > numact) ++sdown;
  numant = numact;
  ++i;
 }
 cout << sup << ' ' << sdown << '\n';
}
int main() {
 int casos, n;
 cin >> casos;
 for (int i = 0; i < casos; i++) {
  cin >> n;
  resuelve(n);
 }
}