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
    int n, k, l, r;
    cin >> n >> k;

    string s;
    cin >> s;
    s = " " + s;

    vi left(k), right(k);
    for (int i = 0; i < k; i++)
        cin >> left[i];
    for (int i = 0; i < k; i++)
        cin >> right[i];

    map<int, pi> range;
    forr(i, 0, k - 1)
    {
        l = left[i], r = right[i];
        forr(j, l, r)
            range[j] = {l, r};
    }

    int q, x;
    cin >> q;
    vi changeLog(n + 1);
    while (q--)
    {
        cin >> x;
        int mn = min(x, range[x].ff + range[x].ss - x);
        changeLog[mn]++;
    }

    forr(i, 0, k - 1)
    {
        int track = 0;
        forr(j, left[i], (left[i]+right[i])/2)
        {
            track += changeLog[j];
            int st = range[j].ff, en = range[j].ss;
            if (track % 2)
                swap(s[j], s[en + st - j]);
        }
    }

    s = s.substr(1);
    print(s);
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