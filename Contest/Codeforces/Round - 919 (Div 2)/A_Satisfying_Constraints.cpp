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
    int n;
    cin >> n;
    vector<int> notEq;

    int greatEq = 0, lessEq = 1e9;

    int type, x;
    while (n--)
    {
        cin >> type >> x;
        if (type == 1)
            greatEq = max(greatEq, x);
        if (type == 2)
            lessEq = min(lessEq, x);

        if (type == 3)
            notEq.push_back(x);
    }

    int ans = (lessEq + 1 - greatEq);
    for (int it : notEq)
    {
        if (it >= greatEq && it <= lessEq)
            ans--;
    }

    if (ans < 0)
        cout << 0;
    else
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
