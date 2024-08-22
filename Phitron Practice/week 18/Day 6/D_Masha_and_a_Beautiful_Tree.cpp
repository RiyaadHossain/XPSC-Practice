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

int n, ans;
vi a;

void solve(int l, int r)
{
    if (r - l + 1 == 1)
        return;

    int mid = (r + l) / 2 + 1;
    int mal = *max_element(a.begin() + l, a.begin() + mid);
    int mar = *max_element(a.begin() + mid, a.begin() + r + 1);

    if (mal > mar)
    {
        ans++;
        forr(i, l, mid - 1)
            swap(a[i], a[mid + (i - l)]);
    }

    solve(l, mid - 1), solve(mid, r);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        a.resize(n);

        forr(i, 0, n - 1)
            cin >> a[i];

        ans = 0;
        solve(0, n - 1);
        is_sorted(all(a)) ? print(ans) : print(-1);
        cout << '\n';
    }

    return 0;
}