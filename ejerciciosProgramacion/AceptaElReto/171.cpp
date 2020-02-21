#include <iostream>
using namespace std;
typedef int tArray[100000];
int numeroedif(const tArray mon, int n)
{
    int num = 1, max = mon[n - 1], i = n - 2;
    while (i >= 0)
    {
        if (mon[i] > max)
        {
            ++num;
            max = mon[i];
        }
        --i;
    }
    return num;
}
int main()
{
    tArray mon;
    int casos = 0, i = 0;
    cin >> casos;
    while (casos != 0)
    {
        i = 0;
        while (i < casos)
        {
            cin >> mon[i];
            ++i;
        }
        cout << numeroedif(mon, i) << "\n";
        cin >> casos;
    }
    return 0;
}