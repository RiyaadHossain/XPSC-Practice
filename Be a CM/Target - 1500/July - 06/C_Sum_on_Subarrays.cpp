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
#define dsFind(ds, x) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;
    k = n * (n + 1) / 2 - k;

    vi a(n);
    bool f = 1;
    forr(i, 0, n - 1)
    {
        if (k >= n - i)
            a[i] = -1000, k += i - n;
        else if (f && k)
            a[i] = -k, k--, f = 0;
        else if (k)
            a[i] = 1, k--;
        else
            a[i] = 2;
    }

    forr(i, 0, n - 1)
        printsp(a[i]);
}

void solve2()
{
    int n, k;
    cin >> n >> k;

    forr(i, 1, n)
    {
        if (k >= i)
            printsp(2), k -= i;
        else if (k > 0)
            printsp((i - k) * (-2) + 1), k = 0;
        else
            printsp(-1000);
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
        cout << '\n';
    }

    return 0;
}