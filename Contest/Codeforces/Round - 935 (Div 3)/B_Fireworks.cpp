#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, m;
    cin >> a >> b >> m;

    long long result = (m / a) + 1 + (m / b) + 1;
    cout << result;
}

int main()
{
    int tt;
    cin >> tt;

    while (tt--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}