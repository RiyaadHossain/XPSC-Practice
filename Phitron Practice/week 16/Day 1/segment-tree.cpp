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

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)
#define forEach(x, ds) for (auto &x : ds)

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;
const int N = 4e5 + 1;

vi a(N), t(N);

void build(int n, int b, int e)
{
    if (b == e)
    {
        t[n] = a[b];
        return;
    }

    int m = (b + e) / 2, l = n * 2, r = n * 2 + 1;
    build(l, b, m);
    build(r, m + 1, e);
    t[n] = t[l] + t[r];
}

void update(int n, int b, int e, int i, int v)
{
    if (i == b && b == e)
    {
        t[n] = v;
        return;
    }

    if (i < b || i > e)
        return;

    int m = (b + e) / 2, l = n * 2, r = n * 2 + 1;
    update(l, b, m, i, v);
    update(r, m + 1, e, i, v);
    t[n] = t[l] + t[r];
}

int query(int n, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return 0;
    if (i <= b && j >= e)
        return t[n];

    int m = (b + e) / 2, l = n * 2, r = n * 2 + 1;
    return query(l, b, m, i, j) + query(r, m + 1, e, i, j);
}

void segmentTree()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    int sign, idx, val, left, right;
    while (m--)
    {
        cin >> sign;
        if (sign == 1)
        {
            cin >> idx >> val;
            update(1, 1, n, idx + 1, val);
        }
        else
        {
            cin >> left >> right;
            println(query(1, 1, n, left + 1, right));
        }
    }
}

int32_t main()
{

    segmentTree();

    return 0;
}