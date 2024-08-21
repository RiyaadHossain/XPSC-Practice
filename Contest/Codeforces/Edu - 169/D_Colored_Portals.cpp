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

map<string, vector<string>> included;
vector<string> allString = {"BG", "BR", "BY", "GR", "GY", "RY"};

bool contain(string s1, string s2)
{
    return (s1[0] == s2[0] || s1[1] == s2[0] || s1[0] == s2[1] || s1[1] == s2[1]);
}

void generate()
{
    forr(i, 0, sz(allString) - 1)
    {
        forr(j, 0, sz(allString) - 1)
        {
            if (i == j)
                continue;
            if (contain(allString[i], allString[j]))
                included[allString[i]].pb(allString[j]);
        }
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<string> s(n);
    forr(i, 0, n - 1)
            cin >>
        s[i];

    map<string, vi> track;
    forr(i, 0, n - 1)
        track[s[i]]
            .pb(i);

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--, r--;

        if (contain(s[l], s[r]))
        {
            println(abs(l - r));
            continue;
        }

        int ans = inf;
        for (string str : included[s[l]])
        {
            if (dsFind(str, track))
            {
                vi indices = track[str];
                int curr = inf;
                int m = sz(indices);
                int it = upper_bound(all(indices), l) - indices.begin();

                if (it != m)
                    curr = abs(l - indices[it]) + abs(indices[it] - r);
                it--;
                if (it >= 0)
                    curr = min(curr, abs(l - indices[it]) + abs(indices[it] - r));

                ans = min(ans, curr);
            }
        }

        ans != inf ? println(ans) : println(-1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generate();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        // cout << '\n';
    }

    return 0;
}