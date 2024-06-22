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
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(rall(a));

    int mx = a[0];

    if (mx * d < c)
    {
        print("Impossible");
        return;
    }

    auto ok = [&](int k) -> bool
    {
        int day = d, coins = 0;

        int it = 0;
        while (day--)
        {
            if (it < n)
                coins += a[it];
            it++;
            (it > k) ? it = 0 : NULL;

            if (coins >= c)
                return 1;
        }

        return 0;
    };

    int ans = 0;
    int left = 0, right = llinf, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (ok(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    if (ans >= llinf)
    {
        print("Infinity");
        return;
    }

    print(ans);
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