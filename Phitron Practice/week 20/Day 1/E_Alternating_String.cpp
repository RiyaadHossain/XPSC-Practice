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
#define lb(x, ds) lower_bound(ds.begin(), ds.end(), x)
#define ub(x, ds) upper_bound(ds.begin(), ds.end(), x)

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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vvi freq(2, vi(26));
    forr(i, 0, n - 1)
        freq[i % 2][s[i] - 'a']++;

    if (n % 2 == 0)
    {
        int ans = n;

        forr(i, 0, 1)
        {
            int mx = 0;
            forr(j, 0, 25)
                mx = max(mx, freq[i][j]);
            ans -= mx;
        }

        print(ans);
        return;
    }

    int ans = n;
    vvi suff(2, vi(26)), pref(2, vi(26));
    forr(i, 0, n - 1)
        suff[i % 2][s[i] - 'a']++;

    forr(i, 0, n - 1)
    {
        suff[i % 2][s[i] - 'a']--;
        int curr = n;
        forr(j, 0, 1)
        {
            int mx = 0;
            forr(k, 0, 25)
                mx = max(mx, pref[j][k] + suff[j ^ 1][k]);
            curr -= mx;
        }
        ans = min(ans, curr);
        pref[i % 2][s[i] - 'a']++;
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