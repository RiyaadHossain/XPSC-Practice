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

    vvi mat1(n, vi(m));
    vvi mat2(n, vi(m));

    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
                cin >>
            mat1[i][j];
    }

    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
                cin >>
            mat2[i][j];
    }

    int nm = n * m;
    vi pos1i(nm), pos1j(nm), pos2i(nm), pos2j(nm);
    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
        {
            int x = mat1[i][j] - 1;
            int y = mat2[i][j] - 1;
            pos1i[x] = pos2i[y] = i;
            pos1j[x] = pos2j[y] = j;
        }
    }

    vector<set<int>> pi(nm), pj(nm);
    forr(i, 0, nm - 1)
    {
        int i1 = pos1i[i], i2 = pos2i[i];
        int j1 = pos1j[i], j2 = pos2j[i];
        pi[i1].insert(i2);
        pj[j1].insert(j2);
    }

    forr(i, 0, nm - 1)
    {
        if (sz(pi[i]) > 1 || sz(pj[i]) > 1)
        {
            no;
            return;
        }
    }

    ye;
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