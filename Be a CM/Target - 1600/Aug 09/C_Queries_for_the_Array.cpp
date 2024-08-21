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
    string s;
    cin >> s;

    int n = sz(s);

    vi track;
    bool ans = 1;
    forr(i, 0, n - 1)
    {
        if (s[i] == '0')
        {
            if (sz(track) < 2 || track.back() == 1)
                ans = 0;
            sz(track) ? track.back() = -1 : NULL;
        }

        if (s[i] == '1')
        {
            if (!track.empty() && track.back() == -1)
                ans = 0;
            sz(track) ? track.back() = 1 : NULL;
        }

        if (s[i] == '+')
        {
            if (!track.empty() && track.back() == -1)
                track.pb(-1);
            else
                track.pb(0);
        }

        if (s[i] == '-')
        {
            if (track.back() == 1)
                track.pop_back(), !track.empty() ? track.back() = 1 : NULL;
            else
                track.pop_back();
        }
    }

    ans ? ye : no;
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