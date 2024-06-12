#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "YES \n"
#define no cout << "NO \n"
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
    int x;
    cin >> x;

    string s1, s2, s3;
    s1 = to_string(x);
    int large = 0, mul = 1;
    for (int i = 1; i < sz(s1); i++)
        large += (9 * mul), mul *= 10;

    int small = x - large;
    s2 = to_string(large), s3 = to_string(small);

    for (int i = 0; i < sz(s2); i++)
    {
        if (s3[i] < '5')
            s2[i] -= ('5' - s3[i]);
    }

    for (int i = 0; i < sz(s2); i++)
    {
        if (s2[i] < '5')
        {
            no;
            return;
        }
    }

    (sz(s2) == sz(s3)) ? ye : no;
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