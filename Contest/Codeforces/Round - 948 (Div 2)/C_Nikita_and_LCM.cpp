#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lc = 1;
    int mx = *max_element(all(arr));
    for (int i = 0; i < n; i++)
    {
        lc = lcm(lc, arr[i]);
        if (lc > mx)
        {
            cout << n;
            return;
        }
    }

    map<int, int> dp, newDp;
    dp[1] = 0;

    for (int i = 0; i < n; i++)
    {
        newDp = dp;
        for (auto [lc, sz] : dp)
        {
            int val = lcm(lc, arr[i]);
            newDp[val] = max(newDp[val], sz + 1);
        }
        dp = newDp;
    }

    int ans = 0;
    set<int> st(all(arr));
    for (auto [x, y] : dp)
    {
        if (!st.count(x))
            ans = max(ans, y);
    }

    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}