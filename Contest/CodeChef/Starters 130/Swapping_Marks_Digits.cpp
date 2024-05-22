#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int x, y;
    cin >> x >> y;

    bool ans = 0;
    if (x > y)
        ans = 1;

    if (x > ((y % 10) * 10) + (y / 10))
        ans = 1;

    x = ((x % 10) * 10) + (x / 10);
    if (x > y)
        ans = 1;
    y = ((y % 10) * 10) + (y / 10);
    if (x > y)
        ans = 1;

    cout << (ans ? ye : no);
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
