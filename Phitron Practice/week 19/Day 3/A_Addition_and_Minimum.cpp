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

class SegmentTree
{
    int n;
    vector<int> a;
    vector<int> t;
    vector<int> lazy;

public:
    SegmentTree(int n)
    {
        this->n = n;
        a.resize(n * 4);
        t.resize(n * 4);
        lazy.resize(n * 4);
    }

    void propagate(int node, int L, int R)
    {
        if (!lazy[node])
            return;

        int left = 2 * node, right = 2 * node + 1;
        if (L != R)
            lazy[left] += lazy[node], lazy[right] += lazy[node];
        t[node] += lazy[node];
        lazy[node] = 0;
    }

    void update(int node, int L, int R, int l, int r, int val)
    {
        propagate(node, L, R);
        if (L > r || R < l)
            return;
        if (l <= L && r >= R)
        {
            lazy[node] = val;
            propagate(node, L, R);
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        update(left, L, mid, l, r, val);
        update(right, mid + 1, R, l, r, val);
        t[node] = min(t[left], t[right]);
    }

    int query(int node, int L, int R, int l, int r)
    {
        propagate(node, L, R);
        if (l > R || r < L)
            return llinf;
        if (l <= L && r >= R)
            return t[node];

        int mid = (L + R) / 2;
        int x = query(node * 2, L, mid, l, r);
        int y = query(node * 2 + 1, mid + 1, R, l, r);
        return min(x, y);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    SegmentTree segTree = SegmentTree(n);

    int l, r, val, sign;
    while (m--)
    {
        cin >> sign;
        if (sign==1)
        {
            cin >> l >> r >> val;
            segTree.update(1, 1, n, l + 1, r, val);
        }
        else
        {
            cin >> l >> r;
            int ans = segTree.query(1, 1, n, l + 1, r);
            println(ans);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}