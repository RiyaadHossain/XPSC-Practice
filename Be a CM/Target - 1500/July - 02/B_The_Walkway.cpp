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

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)
#define dsFind(ds, x) ds.find(x) != ds.end()

// Data Type
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vi a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];

    auto find = [&](int start, int end) -> int
    {
        return (end - start - 1) / d;
    };

    vi pref(m), suff(m);
    pref[0] = 1 + (a[0] + d - 2) / d;
    for (int i = 1; i < m; i++)
        pref[i] = 1 + pref[i - 1] + find(a[i - 1], a[i]);

    suff[m - 1] = 1 + find(a[m - 1], n + 1);
    for (int i = m - 2; i >= 0; i--)
        suff[i] = 1 + suff[i + 1] + find(a[i], a[i + 1]);

    mi mpp;

    int op1 = (a[1] + d - 2) / d + suff[1];
    int op2 = (n - a[m - 2]) / d + pref[m - 2];
    int ans = min(op1, op2);
    mpp[op1]++, mpp[op2]++;

    for (int i = 1; i < m - 1; i++)
    {
        int curr = pref[i - 1] + suff[i + 1] + find(a[i - 1], a[i + 1]);
        mpp[curr]++;
        ans = min(ans, curr);
    }

    printsp(ans);
    print(mpp[ans]);
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