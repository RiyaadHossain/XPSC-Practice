#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    ll a, b, r;
    cin >> a >> b >> r;

    if (a < b)
        swap(a, b);

    ll tmp = a;
    int bit = -1;
    while (tmp)
    {
        tmp >>= 1;
        bit++;
    }

    ll ans = 0, curr;
    bool firstDiff = 0;
    while (bit != -1)
    {
        curr = (1 << bit);
        if ((curr & a) && (curr & b) == 0 && firstDiff)
        {
            if ((ans + curr) <= r)
                ans += curr;
        }
        bit--;
        firstDiff = firstDiff || (curr & a) && ((curr & b) == 0);
    }

    cout << abs((a ^ ans) - (b ^ ans));
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
