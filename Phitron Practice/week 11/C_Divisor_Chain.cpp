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

int getMSBPos(int num)
{
    int pos = 0;
    while (num)
    {
        num >>= 1;
        pos++;
    }

    return pos - 1;
}

void solve()
{
    int n;
    cin >> n;

    int msb = getMSBPos(n);

    vector<int> ans;
    for (int i = 0; i < msb; i++)
    {
        int curr = (1 << i);
        if (n & curr)
            ans.push_back(n), n -= curr;
    }

    while (n)
    {
        ans.push_back(n);
        n /= 2;
    }

    cout << ans.size() << endl;
    for (int it : ans)
        cout << it << " ";
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