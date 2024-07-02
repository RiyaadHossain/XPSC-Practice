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
#define dsFind(ds, x) ds.find(x) != ds.end()

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    set<pii> leaves;
    map<int, pii> child;
    vi parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;

        if (l || r)
            child[i] = {l, r};
        else
            leaves.insert({0, i});

        parent[l] = parent[r] = i;
    }

    vi ans(n + 1, inf);
    while (!leaves.empty())
    {
        auto [c, node] = *leaves.begin();
        leaves.erase(leaves.begin());
        if (c >= ans[node])
            continue;

        ans[node] = c;

        int par = parent[node];
        if (child[par].a == node)
            c += s[par - 1] != 'L', leaves.insert({c, par});
        else
            c += s[par - 1] != 'R', leaves.insert({c, par});
    }

    print(ans[1]);
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