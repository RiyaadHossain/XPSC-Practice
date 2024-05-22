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
    int k, x, a;
    cin >> k >> x >> a;

    bool ans = 1;
    int initial = a - x;
    if (initial <= 0)
        ans = 0;

    int initial2 = initial + (initial * (k - 1));
    initial2 -= x;

    if (initial2 <= a)
        ans = 0;

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
