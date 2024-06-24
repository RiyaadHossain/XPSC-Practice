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

void reverse(vi a, int n)
{
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (idx == -1 || a[idx] > a[i])
            idx = i;
    }

    vector<pii> ans;
    while (a[idx] > -5)
    {
        a[idx] *= 2;
        ans.pb({idx + 1, idx + 1});
    }

    while (a[0] > -20)
    {
        a[0] += a[idx];
        ans.pb({1, idx + 1});
    }

    for (int i = n - 2; i >= 0; i--)
    {
        a[i] += (a[i + 1] * 2);
        ans.pb({i + 1, i + 2});
        ans.pb({i + 1, i + 2});
    }

    println(sz(ans));
    for (pii it : ans)
        cout << it.a << " " << it.b << endl;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (is_sorted(all(a)))
    {
        println(0);
        return;
    }

    if (*max_element(all(a)) < 1)
    {
        reverse(a, n);
        return;
    }

    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        if (idx == -1 || a[idx] < a[i])
            idx = i;
    }

    vector<pii> ans;
    while (a[idx] < 5)
    {
        a[idx] *= 2;
        ans.pb({idx + 1, idx + 1});
    }

    while (a[0] < 20)
    {
        a[0] += a[idx];
        ans.pb({1, idx + 1});
    }

    for (int i = 1; i < n; i++)
    {
        a[i] += (a[i - 1] * 2);
        ans.pb({i + 1, i});
        ans.pb({i + 1, i});
    }

    println(sz(ans));
    for (pii it : ans)
        cout << it.a << " " << it.b << endl;
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
        // cout << '\n';
    }

    return 0;
}