#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<int> graph[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a); // For Undirected graph
    }

    vector<int> edges(n);
    for (int i = 0; i < n; i++)
        edges[i] = graph[i].size();

    sort(all(edges));

    vector<int> newEdges;
    for (int it : edges)
        if (it > 1)
            newEdges.pb(it);

    n = sz(newEdges);

    int x, y;
    if (newEdges[0] == newEdges[1])
        x = newEdges[n - 1], y = newEdges[0];
    else
        x = newEdges[0], y = newEdges[n - 1];

    cout << x << " " << y - 1;
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