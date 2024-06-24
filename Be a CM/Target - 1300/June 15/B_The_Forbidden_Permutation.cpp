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
#define println(...) cout << (__VA_ARGS__) << '\n'

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vi a(n + 1), b(m);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x] = i;
    }

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int ans = inf;
    for (int i = 0; i < m - 1; i++)
    {
        if (a[b[i]] > a[b[i + 1]] || a[b[i]] + d < a[b[i + 1]])
        {
            ans = 0;
            break;
        }

        ans = min(ans, a[b[i + 1]] - a[b[i]]);
        if (d + 1 < n)
        {
            int req = d - (a[b[i + 1]] - 1 - a[b[i]]);
            ans = min(ans, req);
        }
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