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

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int bestA1 = inf, bestA2 = inf;
    forr(i, 0, n - 1)
    {
        bestA1 = min(bestA1, abs(a[0] - b[i]));
        bestA2 = min(bestA2, abs(a[n - 1] - b[i]));
    }

    int bestB1 = inf, bestB2 = inf;
    forr(i, 0, n - 1)
    {
        bestB1 = min(bestB1, abs(b[0] - a[i]));
        bestB2 = min(bestB2, abs(b[n - 1] - a[i]));
    }

    int ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
    ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));

    ans = min(ans, abs(a[0] - b[0]) + bestA2 + bestB2);
    ans = min(ans, abs(a[0] - b[n - 1]) + bestA2 + bestB1);

    ans = min(ans, abs(a[n - 1] - b[0]) + bestA1 + bestB2);
    ans = min(ans, abs(a[n - 1] - b[n - 1]) + bestA1 + bestB1);

    ans = min(ans, abs(b[0] - a[0]) + bestA2 + bestB2);
    ans = min(ans, abs(b[0] - a[n - 1]) + bestA1+ bestB2) ;

    ans = min(ans, abs(b[n - 1] - a[0]) + bestA2 + bestB1);
    ans = min(ans, abs(b[n - 1] - a[n - 1]) + bestA1 + bestB1);

    ans = min(ans, bestA1 + bestA2 + bestB1 + bestB2);

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