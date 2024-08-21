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
const int N = 4e4;

int m;
vi palin = {0};
void generate()
{
    auto isPalin = [&](int num) -> bool
    {
        string num_str = to_string(num);
        string tmp_str = num_str;
        reverse(all(tmp_str));
        return num_str == tmp_str;
    };

    forr(i, 1, N)
    {
        if (isPalin(i))
            palin.pb(i);
    }

    m = sz(palin);
}

vvi dp;
void generateDP()
{
    dp.resize(m + 1, vi(N + 1));
    dp[0][0] = 1;

    forr(i, 1, m)
    {
        forr(j, 0, N)
        {
            if (palin[i] <= j)
                dp[i][j] = (dp[i][j - palin[i]] + dp[i - 1][j]) % mod;
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
}

void solve()
{

    int n;
    cin >> n;

    print(dp[m][n]);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generate();
    generateDP();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}