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
    int x, n;
    cin >> x >> n;

    int ans = x;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i)
            continue;

        if (i >= n)
            ans = min(ans, i);
 
        if ((x / i) >= n)
            ans = min(ans, (x / i));
    }

    cout << (x / ans);
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
