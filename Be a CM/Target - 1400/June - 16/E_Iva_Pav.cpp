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
#define print(...) cout << (__VA_ARGS__)
#define println(...) cout << (__VA_ARGS__) << '\n'

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<vi> prefix(n + 1, vi(32));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if (a[i - 1] & (1 << j))
                prefix[i][j]++;
            prefix[i][j] += prefix[i - 1][j];
        }
    }

    int q;
    cin >> q;

    auto ok = [&](int l, int r, int k) -> bool
    {
        int val = 0;
        for (int i = 0; i < 32; i++)
        {
            bool isSet = (prefix[r][i]  - prefix[l - 1][i]) == r + 1 - l;
            if (isSet)
                val += (1 << i);
        }

        return val >= k;
    };

    auto bs = [&](int l, int k) -> int
    {
        int ans = -1;
        int left = l, right = n, mid;
        while (left <= right)
        {
            mid = (left + right) / 2;

            if (ok(l, mid, k))
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    while (q--)
    {
        int l, k;
        cin >> l >> k;

        cout << bs(l, k) << " ";
    }
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