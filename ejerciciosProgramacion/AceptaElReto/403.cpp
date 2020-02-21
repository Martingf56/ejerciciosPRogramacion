#include <iostream>
#include <string>
using namespace std;
void casoDePrueba()
{
    int m2, n, areasmin = 4050, areamax = 10800;
    cin >> m2 >> n;
    if (m2 >= areasmin * n && m2 <= areamax * n)
    {
        cout << "SI" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
} // casoDePrueba
int main()
{
    unsigned int numCasos, i;
    cin >> numCasos;
    for (i = 0; i < numCasos; ++i)
    {
        casoDePrueba();
    }
    return 0;
}