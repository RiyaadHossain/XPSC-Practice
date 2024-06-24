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

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void findParent(int u, int p, vi &par, vector<vi> &adj)
{
    par[u] = p;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        findParent(v, u, par, adj);
    }
}

void findAns(int u, int p, int &ans, int curr, map<pii, int> &wt, vector<vi> &adj)
{
    ans = max(ans, curr);
    for (int v : adj[u])
    {
        if (p == v)
            continue;
        findAns(v, u, ans, curr + wt[{u, v}], wt, adj);
    }
}

void solve()
{
    int n;
    cin >> n;

    map<pii, int> idx;
    vector<vi> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;

        idx[{u, v}] = idx[{v, u}] = i;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi par(n + 1);
    findParent(1, -1, par, adj);

    map<pii, int> wt;
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == 1)
            wt[{i, par[i]}] = wt[{par[i], i}] = 1;
        if (par[i] > 1)
        {
            int u = i, v = par[u], w = par[v];
            if (idx[{u, v}] > idx[{v, w}])
                wt[{u, v}] = wt[{v, u}] = 0;
            else
                wt[{u, v}] = wt[{v, u}] = 1;
        }
    }

    int ans = 0;
    findAns(1, -1, ans, 0ll, wt, adj);

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