#include <iostream>
#include <string>
using namespace std;
//{Pre: }
void meterCeros(string num)
{
    string ret = "";
    int i = 0;
    while (i < num.length() - 1)
    {
        cout << num[i] << "0";
        ++i;
    }
    cout << num[i] << '\n';
}
//{Post: }
int main()
{
    string num;
    cin >> num;
    while (cin)
    {
        meterCeros(num);
        cin >> num;
    }
    return 0;
}