#include <iostream>
using namespace std;
//{Pre: 0 <= n <= longitud(p)}
long long calcularnum(int p[], int tam)
{
    int i = tam - 1;
    long long suma = 0, total = 0;
    //{ I : (0 <= i <= n) ^ (suma = # k: 0 <= k < i: p[k]) ^ (total = # j : 0 <= j < i: p[j]*suma)}
    while (i >= 0)
    {
        total += p[i] * suma;
        suma += p[i];
        i--;
    }
    return total;
}
//{P.t.: ret = # i : 0 <= i < n : p[i]*suma
//   suma = # k : 0 <= k < i : p[k]
//}
int main()
{
    int nump, p[100000], i = 0;
    cin >> nump;
    while (nump != 0)
    {
        while (nump > i)
        {
            cin >> p[i];
            ++i;
        }
        cout << calcularnum(p, nump) << "\n";
        cin >> nump;
        i = 0;
    }
    return 0;
}