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

void solve2()
{
    int q;
    cin >> q;

    int l, r, c;
    set<pi> left, right;
    map<pi, set<int>> cost;

    auto answer = [&]() -> int
    {
        int le = (*left.begin()).ff;
        int leCost = (*left.begin()).ss;

        int ri = (*right.rbegin()).ff;
        int riCost = -(*right.rbegin()).ss;

        int ans = leCost + riCost;
        if (dsFind(mp(le, ri), cost))
            ans = min(ans, *cost[mp(le, ri)].begin());

        return ans;
    };

    while (q--)
    {
        cin >> l >> r >> c;
        left.insert({l, c});
        right.insert({r, -c});

        cost[{l, r}].insert(c);
        println(answer());
    }
}

void solve()
{
    int n;
    cin >> n;

    int l, r, c;
    int len = 0, lenCost = 0;
    int left = inf, right = 0, leftCost = 0, rightCost = 0;
    while (n--)
    {
        cin >> l >> r >> c;
        if (l < left)
            left = l, leftCost = inf;
        if (l == left)
            leftCost = min(leftCost, c);

        if (r > right)
            right = r, rightCost = inf;
        if (r == right)
            rightCost = min(rightCost, c);

        if (len < r - l + 1)
            len = r - l + 1, lenCost = inf;
        if (len == r - l + 1)
            lenCost = min(lenCost, c);

        int ans = leftCost + rightCost;
        if (len == right - left + 1)
            ans = min(ans, lenCost);

        println(ans);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve2();
        // cout << '\n';
    }

    return 0;
}