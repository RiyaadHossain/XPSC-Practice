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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<pair<pii, int>> op(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;

        op[i] = {{l, r}, d};
    }

    vector<int> all_op(m + 2);
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        all_op[l]++, all_op[r + 1]--;
    }

    for (int i = 1; i <= m; i++)
    {
        all_op[i] += all_op[i - 1];
        op[i].b *= all_op[i];
    }

    vector<int> diff(n + 2);
    for (int i = 1; i <= n; i++)
        diff[i] = arr[i] - arr[i - 1];

    for (auto it : op)
    {
        int l = it.a.a, r = it.a.b, d = it.b;
        diff[l] += d, diff[r + 1] -= d;
    }

    for (int i = 1; i <= n; i++)
        diff[i] += diff[i - 1];

    for (int i = 1; i <= n; i++)
        cout << diff[i] << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}