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

    int l, r;
    vector<pii> segments(n);
    for (int i = 0; i < n; i++)
    {
        cin >> l >> r;
        segments[i] = {l, r};
    }

    auto ok = [&](int k)
    {
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++)
        {
            mn = max(segments[i].first, mn - k);
            mx = min(segments[i].second, mx + k);

            if (mn > mx)
                return 0;
        }

        return 1;
    };

    int ans = 0;
    int left = 0, right = 1e18, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
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
