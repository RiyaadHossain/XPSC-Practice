#include <bits/stdc++.h>
using namespace std;

bool isValid(int x)
{
    int digitCnt = 0;

    while (x > 0)
    {
        x /= 10;
        digitCnt++;
    }

    return digitCnt == 5;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    if (isValid(a * b))
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}