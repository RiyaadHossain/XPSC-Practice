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

int dfs(vvi &graph, vi &vis, int u, int &cut, int target)
{
    vis[u] = 1;
    int totNode = 1;
    for (int v : graph[u])
    {
        if (!vis[v])
            totNode += dfs(graph, vis, v, cut, target);
    }

    if (totNode >= target)
        cut++, totNode = 0;
    return totNode;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int e = n - 1;
    vvi graph(n + 1);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    auto ok = [&](int x) -> bool
    {
        int cut = 0;
        vi vis(n + 1);
        int rem = dfs(graph, vis, 1, cut, x);

        return cut > k || (rem >= x && cut == k);
    };

    int ans = 0;
    int left = 1, right = n, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (ok(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
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