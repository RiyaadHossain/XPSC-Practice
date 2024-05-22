#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<ll> prefix;
ll preSum(int a, int b)
{
    if (a >= m)
        return 0;

    a = a != 0 ? a : 0;
    return prefix[b] - prefix[a];
}

void solve()
{
    cin >> n >> m;

    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    prefix.resize(n, 0);
    prefix[0] = b[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + b[i];

    ll ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i <= m - 1)
        {
            ll mnCost = 1e18;
            while (i >= 0)
                mnCost = min(mnCost, a[i] + preSum(i, m - 1)), i--;
            ans += mnCost;
        }
        else
        {
            ans += min(a[i], b[i]);
        }
    }

    cout << ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}