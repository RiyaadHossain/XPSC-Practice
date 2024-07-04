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

void dfs(int u, vvi &adj, vector<bool> &vis, vi &cost)
{
    int c = 0;
    vis[u] = 1;
    for (int v : adj[u])
    {
        if (!vis[v])
            dfs(v, adj, vis, cost);
        c += cost[v];
    }

    c = sz(adj[u]) ? c : inf;
    cost[u] = min(c, cost[u]);
}

void solve()
{
    int n, k, m;
    cin >> n >> k;

    vi cost(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    int x;
    for (int i = 0; i < k; i++)
        cin >> x, cost[x] = 0;

    vvi adj(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
            cin >> x, adj[i].pb(x);
    }

    vector<bool> vis(n + 1);

    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i, adj, vis, cost);

    for (int i = 1; i <= n; i++)
        printsp(cost[i]);
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