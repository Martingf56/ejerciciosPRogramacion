#include <iostream>
#include <math.h>
using namespace std;
void resuelve(int &num)
{
    int raiz = sqrt(num);
    while (num % raiz != 0)
        --raiz;
    num /= raiz;
}
int main()
{
    int num;
    cin >> num;
    while (num != 0)
    {
        resuelve(num);
        cout << num << '\n';
        cin >> num;
    }
    return 0;
}