#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
#define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forEach(x, ds) for (auto &x : ds)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)

// Shortcut Functions
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcountll(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Constant Varialbes
const int inf = 1e9;
const int llinf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, k;
    cin >> n >> k;

    int val;
    vector<pi> a(n);
    for (int i = 0; i < n; i++)
        cin >> val, a[i] = {val, i};

    vi b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(all(a));

    auto getMid = [&](int idx) -> int
    {
        int mid;
        if (idx + 1 <= n / 2)
            mid = (n + 2) / 2;
        else
            mid = n / 2;
        return mid - 1;
    };

    int ans = 0;
    forr(i, 0, n - 1)
    {
        int mid = getMid(i), idx = a[i].ss;
        int curr = a[i].ff + a[mid].ff;
        if (b[idx])
            curr += k;
        ans = max(ans, curr);
    }

    auto ok = [&](int x) -> bool
    {
        int cnt = 0, rem = k;
        rforr(i, n - 2, 0)
        {
            int val = a[i].ff, idx = a[i].ss;
            if (val >= x)
                cnt++;
            else if (b[idx] && val < x && x - val <= rem)
                rem -= (x - val), cnt++;
        }

        return cnt >= (n + 1) / 2;
    };

    int mxMid = 0;
    int left = 0, right = llinf, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (ok(mid))
            mxMid = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    ans = max(ans, mxMid + a.back().ff);
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