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
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 1)
            continue;
        cnt1 += (a[i] == 1);
        cnt2 += (b[i] == 1);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1 && b[i] == 1)
            (cnt1 <= cnt2) ? cnt1++ : cnt2++;

        if (a[i] == -1 && b[i] == -1)
            (cnt1 >= cnt2) ? cnt1-- : cnt2--;
    }

    print(min(cnt1, cnt2));
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