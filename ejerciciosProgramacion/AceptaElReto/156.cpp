#include <iostream>
#include <stdlib.h>
using namespace std;
int resuelve(int num) {
 int numact, sum = 0;
 cin >> numact;
 while (numact != -1) {
  sum += abs(numact - num);
  num = numact;
  cin >> numact;
 }
 return sum;
}
int main() {
 int num;
 cin >> num;
 while (num >= 0){
  cout << resuelve(num) << '\n';
  cin >> num;
 }
 return 0;
}