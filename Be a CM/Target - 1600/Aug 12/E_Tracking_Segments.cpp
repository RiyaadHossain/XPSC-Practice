#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
#define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forEach(x, ds) for (auto &x : ds)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)

// Shortcut Functions
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcountll(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Constant Varialbes
const int inf = 1e9;
const int llinf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<pi> seg(m);
    forr(i, 0, m - 1)
            cin >>
        seg[i].ff >> seg[i].ss;

    int q;
    cin >> q;
    vi ord(q);
    forr(i, 0, q - 1)
            cin >>
        ord[i];

    auto ok = [&](int m) -> bool
    {
        vi a(n + 1);
        forr(i, 0, m)
            a[ord[i]] = 1;

        vi pref(n + 1);
        forr(i, 1, n)
            pref[i] = pref[i - 1] + a[i];

        for(auto [x,y]:seg)
        {
            if (pref[y] - pref[x - 1] > (y - x + 1) / 2)
                return 1;
        }

        return 0;
    };


    int ans = -1;
    int left = 0, right = q-1, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (ok(mid))
            ans = mid+1, right = mid - 1;
        else
            left = mid + 1;
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