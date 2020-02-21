#include <iostream>
using namespace std;
int resuelve(int n)
{
    if (n < 6)
        return n;
    return 10 * resuelve(n / 6) + n % 6;
}
int main()
{
    int casos, n;
    cin >> casos;
    for (int i = 0; i < casos; ++i)
    {
        cin >> n;
        cout << resuelve(n) << '\n';
    }
    return 0;
}