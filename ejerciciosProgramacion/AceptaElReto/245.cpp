#include <iostream>
using namespace std;
//{Pre: 2 <= n <= longitud(v)}
bool resuelve(int n)
{
    int i = 1, conta = 0, contd = 0;
    long long int hermanoant, hermanoact;
    cin >> hermanoact;
    hermanoant = hermanoact;
    while (i < n)
    {
        cin >> hermanoact;
        if (hermanoact > hermanoant)
            ++conta;
        else if (hermanoact < hermanoant)
            ++contd;
        hermanoant = hermanoact;
        ++i;
    }
    return n != 1 && (n - 1 == conta || n - 1 == contd);
}
//{P.t: ret = (2 <= i < n) ^ (i == n-1) }
int main()
{
    int casos;
    cin >> casos;
    while (casos != 0)
    {
        if (resuelve(casos))
            cout << "DALTON\n";
        else
            cout << "DESCONOCIDOS\n";
        cin >> casos;
    }
    return 0;
}