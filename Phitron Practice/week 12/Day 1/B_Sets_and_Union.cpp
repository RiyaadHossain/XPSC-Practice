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
    int n, m, x;
    cin >> n;

    set<int> uni;
    vector<set<int>> allSet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        set<int> tmp;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            tmp.insert(x), uni.insert(x);
        }
        allSet[i] = tmp;
    }

    int ans = 0;
    for (int i = 1; i <= 50; i++)
    {
        if (!uni.count(i))
            continue;

        set<int> tmp;
        for (set it : allSet)
        {
            if (!it.count(i))
                tmp.insert(all(it));
        }

        ans = max(ans, sz(tmp));
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