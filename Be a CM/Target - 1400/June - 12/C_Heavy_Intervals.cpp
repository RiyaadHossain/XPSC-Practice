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

    vector<pair<int, char>> interval;
    for (int i = 0; i < n * 2; i++)
    {
        int x;
        cin >> x;
        if (i < n)
            interval.pb({x, 'l'});
        else
            interval.pb({x, 'r'});
    }

    vi c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(all(interval));
    vi diff;

    stack<int> st;
    for (int i = 0; i < n * 2; i++)
    {
        int x = interval[i].a;
        char sign = interval[i].b;

        if (sign == 'l')
            st.push(x);
        else
            diff.pb(x - st.top()), st.pop();
    }

    sort(all(diff)), sort(rall(c));

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (diff[i] * c[i]);

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