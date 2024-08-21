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
    bool oddOrEven;
    vector<int> a;

public:
    vector<int> t;
    SegmentTree(int base, int n)
    {
        this->n = n;
        a.resize(n * 4);
        t.resize(n * 4);
        oddOrEven = base % 2;
    }

    void input()
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

    void build(int node, int L, int R)
    {
        if (L == R)
        {
            t[node] = a[L];
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        build(left, L, mid);
        build(right, mid + 1, R);

        int logVal = log2(node);
        t[node] = (logVal % 2 == oddOrEven) ? (t[left] ^ t[right]) : (t[left] | t[right]);
    }

    void update(int node, int L, int R, int pos, int val)
    {
        if (pos < L || pos > R)
            return;
        if (L == R)
        {
            t[node] = val;
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        update(left, L, mid, pos, val);
        update(right, mid + 1, R, pos, val);

        int logVal = log2(node);
        t[node] = (logVal % 2 == oddOrEven) ? (t[left] ^ t[right]) : (t[left] | t[right]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;

    int len = (1 << n);
    SegmentTree segTree = SegmentTree(n, len);
    segTree.input();
    segTree.build(1, 1, len);

    int pos, val;
    while (q--)
    {
        cin >> pos >> val;
        segTree.update(1, 1, len, pos, val);
        println(segTree.t[1]);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}