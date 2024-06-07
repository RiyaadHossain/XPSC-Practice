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

const int N = 2e6;

void solve()
{
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> temp(N + 2);
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        temp[l]++, temp[r + 1]--;
    }

    for (int i = 1; i <= N; i++)
        temp[i] += temp[i - 1];

    for (int i = 1; i <= N; i++)
    {
        if (temp[i] >= k)
            temp[i] = 1;
        else
            temp[i] = 0;
    }

    for (int i = 1; i <= N; i++)
        temp[i] += temp[i - 1];

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        int ans = temp[r] - temp[l - 1];
        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}