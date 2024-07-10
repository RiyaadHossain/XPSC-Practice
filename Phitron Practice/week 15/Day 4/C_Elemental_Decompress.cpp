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

void solve()
{
    int n;
    cin >> n;

    set<int> rem;
    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], rem.insert(i + 1);

    map<int, vi> freq;
    forr(i, 0, n - 1)
    {
        freq[a[i]].pb(i);
        rem.erase(a[i]);
    }

    bool poss = 1;
    vi remV(all(rem));
    int j = 0;
    vi p(n), q(n);
    for (auto [el, ind] : freq)
    {
        if (sz(ind) > 2)
            poss = 0;

        int ff = ind.front(), ss = ind.back();
        p[ff] = el, q[ss] = el;

        if (ff != ss)
            p[ss] = q[ff] = remV[j++];
    }

    auto check = [&]() -> bool
    {
        forr(i, 0, n - 1) if (max(p[i], q[i]) != a[i]) return false;

        return true;
    };

    poss = check();

    if (poss)
    {
        ye;
        println(' ');
        forr(i, 0, n - 1)
            printsp(p[i]);
        println(' ');
        forr(i, 0, n - 1)
            printsp(q[i]);
    }
    else
        no;
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