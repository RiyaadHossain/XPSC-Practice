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

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)
#define forEach(x, ds) for (auto &x : ds)

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)
#define dsFind(ds, x) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, s1, s2, x;
    cin >> n >> s1 >> s2;

    vector<pi> a(n);
    for (int i = 0; i < n; i++)
        cin >> x, a[i] = {x, i};

    sort(rall(a));

    vi v1, v2;
    int tmp1 = s1, tmp2 = s2;
    forr(i, 0, n - 1)
    {
        if (tmp1 <= tmp2)
            v1.pb(a[i].b + 1), tmp1 += s1;
        else
            v2.pb(a[i].b + 1), tmp2 += s2;
    }

    printsp(sz(v1));
    forr(i, 0, sz(v1) - 1)
        printsp(v1[i]);

    println(' ');

    printsp(sz(v2));
    forr(i, 0, sz(v2) - 1)
        printsp(v2[i]);
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