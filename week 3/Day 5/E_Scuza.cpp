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
    ll n, q;
    cin >> n >> q;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll pre[n];
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
        pre[i] = pre[i - 1] + arr[i];

    vector<ll> maxPre(n);
    ll mx = maxPre[0];
    for (int i = 0; i < n; i++)
        mx = max(mx, arr[i]), maxPre[i] = mx;

    ll arr2[q];
    for (int i = 0; i < q; i++)
        cin >> arr2[i];

    for (int i = 0; i < q; i++)
    {
        int it = upper_bound(maxPre.begin(), maxPre.end(), arr2[i]) - maxPre.begin();
        if (it == 0)
            cout << 0 << " ";
        else
            cout << pre[it - 1] << " ";
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
