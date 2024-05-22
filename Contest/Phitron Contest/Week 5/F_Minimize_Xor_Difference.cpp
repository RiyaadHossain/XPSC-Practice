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

    if (x == y)
    {
        cout << 0;
        return;
    }

    if (x < y)
        swap(x, y);

    int bit;
    for (int i = 31; i >= 0; i--)
    {
        bit = 1 << i;
        if ((x & bit) != (y & bit))
        {
            bit = i;
            break;
        }
    }

    int ans = 0;
    for (int i = bit - 1; i >= 0; i--)
    {
        bit = 1 << i;
        if ((x & bit) && !(y & bit))
            ans += bit;
    }

    cout << ans;
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
