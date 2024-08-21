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

void solve()
{
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vvi a(n, vi(m));
    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
                cin >>
            a[i][j];
    }

    vi cost(n);
    forr(i, 0, n - 1)
    {
        vi dp(m);
        set<pi> st;
        rforr(j, m - 1, 0)
        {
            if (j >= m - d - 1)
            {
                dp[j] = a[i][j] + 1 + (j < m - 1);
                st.insert({dp[j], j});
                continue;
            }

            while (sz(st) > 1 && (*st.begin()).ss > j + d + 1)
                st.erase(st.begin());

            dp[j] = a[i][j] + 1 + (*st.begin()).ff;
            st.insert({dp[j], j});
        }

        cost[i] = dp[0];
    }

    int tmp = 0;
    forr(i, 0, k - 1)
        tmp += cost[i];

    int ans = tmp;
    forr(i, k, n - 1)
    {
        tmp -= cost[i - k];
        tmp += cost[i];
        ans = min(ans, tmp);
    }

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