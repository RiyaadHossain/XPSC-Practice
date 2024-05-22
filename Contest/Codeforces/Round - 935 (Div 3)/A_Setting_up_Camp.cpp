#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;

    int result = a;

    int universNeed = (b % 3 ? 3 - (b % 3) : 0);
    if (universNeed > c)
    {
        cout << -1;
        return;
    }

    result += (b + universNeed) / 3;
    result += ((c - universNeed) / 3) + ((c - universNeed) % 3 ? 1 : 0);
    cout << result;
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