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
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (accumulate(all(a), 0) % 2)
    {
        println(-1);
        return;
    }

    vpi seg;
    int i = 0;
    while (i < n)
    {
        if (a[i] == 0)
        {
            seg.pb({i, i}), i++;
            continue;
        }

        int left = i;
        i++;
        while (a[i] == 0)
            i++;

        if (a[left] + a[i] == 0)
        {
            seg.pb({left, left});
            seg.pb({i, i});
            if (i - left > 1)
                seg.pb({left + 1, i - 1});
        }
        else
        {
            if ((i - left + 1) % 2 == 0)
                seg.pb({left, i});
            else
                seg.pb({left, i - 2}), seg.pb({i - 1, i});
        }

        i++;
    }

    sort(all(seg));
    println(sz(seg));
    forEach(x, seg)
        printsp((x.a + 1)),
        println((x.b + 1));
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
        // cout << '\n';
    }

    return 0;
}