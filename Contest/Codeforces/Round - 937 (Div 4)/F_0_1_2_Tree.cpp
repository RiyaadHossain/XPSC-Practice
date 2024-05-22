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
    ll a, b, c;
    cin >> a >> b >> c;

    if (a + 1 != c)
    {
        cout << -1;
        return;
    }

    ll h = log2(c * 2 - 1);
    ll leaves = 1 << h;
    leaves -= c;
    ll xh = max(b - leaves, 0ll);
    ll minHi = h + (xh + c - 1) / c;
    cout << minHi;
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
