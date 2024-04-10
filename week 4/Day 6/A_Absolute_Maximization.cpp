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
    int n;
    cin >> n;

    int arr[n];
    int mx = INT_MIN, mn = INT_MAX;
    for (int i = 0; i < n; i++)
        cin >> arr[i], mx = max(mx, arr[i]), mn = min(mn, arr[i]);

    int ans = mx - mn;

    for (int i = 0; i < n; i++)
        mx |= arr[i], mn &= arr[i];


    ans = max(ans, mx - mn);
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
