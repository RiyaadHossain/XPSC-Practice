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
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto get = [&](string s)
    {
        int cnt = 0;
        for (int i = 0; i < sz(s); i++)
            cnt += (s[i] - '0');
        return cnt;
    };

    map<pii, int> mpp;
    for (string str : a)
    {
        int sum = 0, m = sz(str);
        int tot = get(str);
        mpp[{tot, m}]++;

        if (m % 2)
        {
            for (int j = 0; j < m / 2; j++)
            {
                sum += (str[j] - '0');
                int len = m - 2 * (j + 1);
                mpp[{tot - 2 * sum, len}]++;
            }
            sum = 0;
            for (int j = m - 1; j > m / 2; j--)
            {
                sum += (str[j] - '0');
                int len = 2 * j - m;
                mpp[{tot - 2 * sum, len}]++;
            }
        }

        if (m == 4)
        {
            mpp[{tot - 2 * (str[0] - '0'), 2}]++;
            mpp[{tot - 2 * (str[m - 1] - '0'), 2}]++;
        }
    }

    int ans = 0;
    for (string str : a)
    {
        int tot = get(str), len = sz(str);
        ans += mpp[{tot, len}];
    }

    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}