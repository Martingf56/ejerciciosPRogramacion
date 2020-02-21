#include <iostream>
using namespace std;
int tinta(int n)
{
    if (n == 1)
        return 4;
    return n * 4 + 4 * tinta(n / 2);
}
int main()
{
    int n;
    cin >> n;
    while (cin)
    {
        cout << tinta(n) << '\n';
        cin >> n;
    }
    return 0;
}