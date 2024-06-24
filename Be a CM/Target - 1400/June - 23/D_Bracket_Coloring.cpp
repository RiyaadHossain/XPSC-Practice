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
    int n;
    cin >> n;

    string s;
    cin >> s;

    vi ans(n);
    stack<char> open, close;
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            if (close.empty())
                open.push(ch), ans[i] = 1;
            else
                close.pop(), ans[i] = 2;
        }
        else
        {
            if (open.empty())
                close.push(ch), ans[i] = 2;
            else
                open.pop(), ans[i] = 1;
        }
    }

    if (sz(open) || sz(close))
    {
        print(-1);
        return;
    }

    unordered_set<int> ust(all(ans));
    bool single = ust.size() == 1;

    println(single ? 1 : 2);
    for (int it : ans)
        printsp(single ? 1 : it);
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