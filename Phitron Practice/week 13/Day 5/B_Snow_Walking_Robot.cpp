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
    string s;
    cin >> s;

    int l = 0, r = 0, u = 0, d = 0;
    for (int i = 0; i < sz(s); i++)
    {
        l += (s[i] == 'L');
        r += (s[i] == 'R');
        u += (s[i] == 'U');
        d += (s[i] == 'D');
    }

    int lr = min(l, r), ud = min(u, d);
    if (!lr && !ud)
    {
        print(0);
        return;
    }

    if (!lr || !ud)
    {
        println(2);
        if (!lr)
            print("UD");
        else
            print("LR");
        return;
    }

    string res;
    res += string(lr, 'L');
    res += string(ud, 'U');
    res += string(lr, 'R');
    res += string(ud, 'D');

    println(sz(res));
    print(res);
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