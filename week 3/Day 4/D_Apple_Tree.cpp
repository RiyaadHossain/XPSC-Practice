#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void leafNodes(vector<int> adj[], ll leaves[], int par, int u)
{
    if (adj[u].size() == 1 && adj[u][0] == par)
    {
        leaves[u] = 1;
        return;
    }

    int totLeaves = 0;
    for (int v : adj[u])
    {
        if (v != par)
            leafNodes(adj, leaves, u, v), totLeaves += leaves[v];
    }
    leaves[u] = totLeaves;
}

void solve()
{
    int n, e;
    cin >> n;
    e = n - 1;

    vector<int> adj[n];
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ll leaves[n];
    leafNodes(adj, leaves, -1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        a--, b--;

        cout << leaves[a] * leaves[b];
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
