#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int x, y;
    cin >> x >> y;

    if (x < 50)
        cout << 'Z';
    else if (y < 50)
        cout << 'F';
    else
        cout << 'A';
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
