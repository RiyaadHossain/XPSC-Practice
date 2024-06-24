#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "Yes"
#define no cout << "No"
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

void solve()
{
    int n;
    cin >> n;

    map<int, int> cnt;

    vector<vi> bits(n);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        vi tmp(m);
        for (int j = 0; j < m; j++)
            cin >> tmp[j], cnt[tmp[j]]++;

        bits[i] = tmp;
    }

    for (vi it : bits)
    {
        bool f = 1;
        for (int i : it)
        {
            if (cnt[i] == 1)
            {
                f = 0;
                break;
            };
        }
        if (f)
        {
            ye;
            return;
        }
    }

    no;
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