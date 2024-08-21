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
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;
const int N = 1e4;

void solve()
{
    int n;
    cin >> n;

    string s;
    forr(i, 1, 10)
        s += to_string(n);

    int n_len = sz(to_string(n));

    vector<pi> ans;
    forr(i, 2, N)
    {
        int tot = n * i;
        int tot_len = sz(to_string(tot));
        int str_len = n_len * i;
        rforr(j, str_len - 1, str_len - tot_len)
        {
            int rem = tot - j;
            if (to_string(rem) == s.substr(0, str_len - j))
                ans.pb({i, j});
        }
    }

    println(sz(ans));
    forr(i, 0, sz(ans) - 1)
        printsp(ans[i].a),
        println(ans[i].b);
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
        // cout << '\n';
    }

    return 0;
}