#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 6;
        return;
    }

    int result = n / 2 * 13 + (n % 2 ? 6 : 0);
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