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

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
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
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = (n * (n + 1)) / 2;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        arr[i] = s[i] == '0' ? -1 : 1;

    map<int, int> mpp;
    mpp[0] = 1;

    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        cnt += mpp[sum - 0];
        mpp[sum]++;
    }

    cout << ans + cnt;
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