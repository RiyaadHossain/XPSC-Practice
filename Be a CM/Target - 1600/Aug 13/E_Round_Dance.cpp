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
    int n;
    cin >> n;

    vi a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<set<int>> graph(n + 1);
    forr(i, 1, n)
    {
        graph[i].insert(a[i]);
        graph[a[i]].insert(i);
    }

    vi vis(n + 1);

    bool iscycle = 0;
    function<bool(int, int)> dfs = [&](int u, int par) -> bool
    {
        vis[u] = 1;
        bool ok = 0;
        for (int v : graph[u])
        {
            if (par != v && vis[v])
                return 1;
            if (!vis[v])
                ok |= dfs(v, u);
        }

        return ok;
    };

    int cycle = 0, bamboo = 0;
    forr(i, 1, n)
        if (!vis[i])
            dfs(i, -1) ? cycle++ : bamboo++;

    int mn = cycle + min(bamboo, 1ll);
    printsp(mn), print(cycle + bamboo);
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