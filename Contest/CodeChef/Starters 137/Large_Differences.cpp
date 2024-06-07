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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    int ans = 0;
    arr[0] = arr[1], arr[n + 1] = arr[n];
    for (int i = 1; i <= n; i += 2)
        ans += abs(arr[i] - arr[i - 1]) + abs(arr[i] - arr[i + 1]);

    int result = ans;
    arr[0] = 1, arr[n + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int tmp = ans;
        if (i > 1)
            tmp -= abs(arr[i] - arr[i - 1]);
        if (i < n)
            tmp -= abs(arr[i] - arr[i + 1]);
        tmp += (abs(1 - arr[i - 1]) + abs(1 - arr[i + 1]));
        result = max(result, tmp);
    }

    arr[0] = k, arr[n + 1] = k;
    for (int i = 1; i <= n; i++)
    {
        int tmp = ans;
        if (i > 1)
            tmp -= abs(arr[i] - arr[i - 1]);
        if (i < n)
            tmp -= abs(arr[i] - arr[i + 1]);
        tmp += (abs(k - arr[i - 1]) + abs(k - arr[i + 1]));
        result = max(result, tmp);
    }

    cout << result;
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