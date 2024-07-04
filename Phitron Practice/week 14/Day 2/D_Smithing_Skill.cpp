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
#define printsp(...) cout << (__VA_ARGS__) << ' '
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
#define dsFind(ds, x) ds.find(x) != ds.end()

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, m, x;
    cin >> n >> m;

    vi a(n), b(n);
    map<int, pii> diff;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (dsFind(diff, a[i] - x))
        {
            if (x < diff[a[i] - x].a)
                diff[a[i] - x] = {x, i};
        }
        else
            diff[a[i] - x] = {x, i};
    }

    map<int, int> c;
    for (int i = 0; i < m; i++)
        cin >> x, c[x]++;

    int ans = 0;
    for (auto [diff, tmp] : diff)
    {
        auto [bi, i] = tmp;
        auto it = c.lower_bound(a[i]);
        while (it != c.end())
        {
            int cnt = (*it).b;
            int ci = (*it).a;
            int curr = (ci - bi) / diff;
            ans += 2 * curr * cnt;
            c[ci - curr * diff] += cnt;

            c.erase(it);
            it = c.lower_bound(a[i]);
        }
    }

    print(ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}