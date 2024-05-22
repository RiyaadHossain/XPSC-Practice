#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    int a[k + 1], b[k + 1];
    a[0] = 0, b[0] = 0;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    while (q--)
    {
        int d;
        cin >> d;

        if (d == n)
        {
            cout << b[k] << " ";
            continue;
        }

        auto it = upper_bound(a, a + k + 1, d) - a;

        int ans = b[it - 1];
        int extra_dis = d - a[it - 1];
        int time = b[it] - b[it - 1];
        int dis = a[it] - a[it - 1];

        ans += (time * extra_dis) / dis;
        cout << ans << " ";
    }
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
