#include <iostream>
using namespace std;
int main()
{
    int n, uvas, pochas, tanto, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        cin >> uvas >> pochas >> tanto;
        while (uvas > tanto)
        {
            uvas -= tanto;
            sum += pochas;
        }

        if (uvas <= 0)
            cout << sum << '\n';
        else if (uvas < pochas)
            cout << sum + uvas << '\n';
        else
            cout << sum + pochas << '\n';
    }
    return 0;
}