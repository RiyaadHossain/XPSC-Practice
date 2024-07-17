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
#define a first
#define b second
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
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

int inversion(vi &arr, int left, int right)
{
    if (left == right)
        return 0;

    int mid = (left + right) / 2;
    int x = inversion(arr, left, mid);
    int y = inversion(arr, mid + 1, right);

    vi tmp;
    int i = left, j = mid + 1, inv = 0;
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            tmp.pb(arr[i++]), inv += j - mid - 1;
        else
            tmp.pb(arr[j++]);
    }

    while (i <= mid)
        tmp.pb(arr[i++]), inv += j - mid - 1;
    while (j <= right)
        tmp.pb(arr[j++]);

    forr(i, left, right)
        arr[i] = tmp[i - left];

    return x + y + inv;
}

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vi tmp1(all(a)), tmp2(all(b));
    sort(all(tmp1)), sort(all(tmp2));
    if (tmp1 != tmp2)
    {
        no;
        return;
    }

    int x = inversion(a, 0, n - 1) % 2;
    int y = inversion(b, 0, n - 1) % 2;

    x == y ? ye : no;
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