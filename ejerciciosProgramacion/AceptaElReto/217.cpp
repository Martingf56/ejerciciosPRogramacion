#include <iostream>
#include <string>
using namespace std;
bool casoDePrueba()
{
    int caso;
    cin >> caso;
    if (caso == 0)
        return false;
    else
    {
        if (caso % 2 == 0)
        {
            cout << "DERECHA" << endl;
        }
        else
        {
            cout << "IZQUIERDA" << endl;
        }
        return true;
    }
} // casoDePrueba
int main()
{
    while (casoDePrueba())
    {
    }
    return 0;
}