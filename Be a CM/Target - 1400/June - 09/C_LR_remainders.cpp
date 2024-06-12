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

bool powermod(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int product = 1;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i], product *= arr[i];

    string s;
    cin >> s;

    int left = 0, right = n - 1;
    vector<int> idx(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            idx[i] = left++;
        else
            idx[i] = right--;
    }

    reverse(all(s)), reverse(all(idx));

    vector<int> ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = (arr[idx[i]] * (i > 0 ? ans[i - 1] : 1)) % m;

    reverse(all(ans));
    for (auto it : ans)
        cout << it << " ";
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