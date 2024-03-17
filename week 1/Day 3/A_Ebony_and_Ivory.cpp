#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool ans = 0;
    if (a + b == c)
        ans = 1;

    int temp = c;
    while (temp >= 0)
    {
        if (temp % b == 0)
        {
            ans = 1;
            break;
        }
        temp -= a;
    }

    temp = c;
    while (temp >= 0)
    {
        if (temp % a == 0)
        {
            ans = 1;
            break;
        }
        temp -= b;
    }

    cout << (ans ? "Yes" : "No");

    return 0;
}