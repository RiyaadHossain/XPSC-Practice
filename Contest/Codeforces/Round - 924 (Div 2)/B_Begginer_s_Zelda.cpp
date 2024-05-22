#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dfs(vector<int> graph[], vector<int> &vis, int src)
{
    vis[src] = 1;

    int leaf = (graph[src].size() == 1);
    for (int ch : graph[src])
        if (!vis[ch])
            leaf += dfs(graph, vis, ch);

    return leaf;
}

void solve()
{
    int n, e;
    cin >> n;
    e = n - 1;
    vector<int> graph[n + 1];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> vis(n + 1, 0);
    int leaves = dfs(graph, vis, 1);

    cout << (leaves + 1) / 2;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
