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

    map<int, vi> mpp;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], mpp[a[i] % k].pb(a[i] / k);

    vi rem;
    int ans = 0, cnt = 0;
    for (auto [x, vec] : mpp)
    {
        cnt += sz(vec) % 2;
        if (sz(vec) % 2)
        {
            rem = vec;
            continue;
        }

        sort(rall(vec));
        for (int i = 0; i < sz(vec); i += 2)
            ans += (vec[i] - vec[i + 1]);
    }

    if (cnt >= 2)
    {
        print(-1);
        return;
    }

    int m = sz(rem);
    if (m >= 3)
    {
        sort(all(rem));
        vi prefix(m), suffix(m);

        prefix[1] = rem[1] - rem[0];
        for (int i = 3; i < m; i += 2)
            prefix[i] += prefix[i - 2] + (rem[i] - rem[i - 1]);

        suffix[m - 2] = rem[m - 1] - rem[m - 2];
        for (int i = m - 4; i >= 0; i -= 2)
            suffix[i] += suffix[i + 2] + (rem[i + 1] - rem[i]);


        int tmp = inf;
        for (int i = 0; i < m; i += 2)
        {
            int curr = 0;
            if (i > 0)
                curr += prefix[i - 1];
            if (i < m - 1)
                curr += suffix[i + 1];

            tmp = min(tmp, curr);
        }

        ans += tmp;
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