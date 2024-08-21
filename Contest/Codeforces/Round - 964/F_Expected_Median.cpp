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
const int N = 1e6 + 1;

vi fact(N, 1);
void precompute()
{
    fact[1] = 1;
    forr(i, 2, N - 1)
        fact[i] = (fact[i - 1] * i) % mod;
}

int powm(int x, int n)
{
    x %= mod;
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;
    int p = powm(x * x, n / 2);
    if (n % 2)
        return p * x % mod;
    else
        return p;
}

int mod_div(int p, int q) { return p % mod * powm(q, mod - 2) % mod; }

void solve()
{
    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int c1 = count(all(a), 1ll);
    int c0 = count(all(a), 0ll);

    auto nCr = [&](int n, int r)
    {
        if (r > n)
            return 0ll;
        return mod_div(fact[n], fact[n - r] * fact[r]);
    };

    int req = (k + 1) / 2;
    int ans = 0;
    forr(i, req, min(k, c1))
        ans = (ans + ((nCr(c1, i) * nCr(c0, k - i)) % mod)) % mod;

    print(ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}