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
    int n, m;
    cin >> n >> m;

    vector<string> a(n + 1);
    forr(i, 1, n)
            cin >>
        a[i];

    map<string, vi> pref, suff;
    vector<string> colors = {"BR", "BG", "BY", "GR", "GY", "RY"};
    for (auto col : colors)
        pref[col] = vi(n + 2, -1), suff[col] = vi(n + 2, -1);

    forr(i, 1, n)
    {
        pref[a[i]][i] = i;
        for (auto &[x, y] : pref)
            y[i + 1] = y[i], pref[x] = y;
    }

    rforr(i, n, 1)
    {
        suff[a[i]][i] = i;

        for (auto &[x, y] : suff)
            y[i - 1] = y[i], suff[x] = y;
    }

    auto contains = [&](string str1, string str2) -> bool
    {
        return str1[0] == str2[0] || str1[0] == str2[1] || str1[1] == str2[0] || str1[1] == str2[1];
    };

    int l, r;
    while (m--)
    {
        cin >> l >> r;

        if (l > r)
            swap(l, r);

        if (contains(a[l], a[r]))
        {
            println(r - l);
            continue;
        }

        int ans = inf;
        for (auto &col : colors)
        {
            if (col != a[l] && col != a[r])
            {
                if (pref[col][r] != -1 && pref[col][r] > l)
                {
                    ans = r - l;
                    break;
                }

                if (pref[col][l] != -1)
                    ans = min(ans, 2 * (l - pref[col][l]) + r - l);
                if (suff[col][r] != -1)
                    ans = min(ans, 2 * (suff[col][r] - r) + r - l);
            }
        }

        ans = ans == inf ? -1 : ans;
        println(ans);
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
        solve();
        // cout << '\n';
    }

    return 0;
}