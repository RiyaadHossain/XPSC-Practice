#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
// #define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << endl

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

    mi node;

    auto ask = [&](int source, int dest) -> int
    {
        cout << "? " << source << " " << dest << endl;
        fflush(stdout);
        int d;
        cin >> d;
        return d;
    };

    vvi graph(n + 1);
    forr(i, 2, n)
    {
        if (node[i])
            continue;

        int source = 1, dest = i;
        while (source != i)
        {
            int d = ask(source, dest);
            if (d == source)
            {
                node[dest] = 1;
                graph[source].pb(dest);
                source = dest;
                dest = i;
            }
            else if (node[d])
                source = d;
            else
                dest = d;
        }
    }

    auto printNodes = [&](int u)
    {
        for (auto v : graph[u])
            printsp(u), printsp(v);
        fflush(stdout);
    };

    printsp("!");
    forr(i, 1, n) if (sz(graph[i])) printNodes(i);
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
        cout << endl;
    }

    return 0;
}