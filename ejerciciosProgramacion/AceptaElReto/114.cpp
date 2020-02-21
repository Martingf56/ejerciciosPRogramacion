#include <iostream>
using namespace std;
int calcularfact(int num)
{
    int ulti = 1;
    while (num > 1)
    {
        ulti *= num;
        --num;
    }
    return ulti % 10;
}
int main()
{
    int numc = 0, num, ret = 0;
    cin >> numc;
    while (numc != 0)
    {
        cin >> num;
        if (num == 0)
            ret = 1;
        else if (num <= 4)
            ret = calcularfact(num);
        else
            ret = 0;
        cout << ret << "\n";
        --numc;
    }
    return 0;
}