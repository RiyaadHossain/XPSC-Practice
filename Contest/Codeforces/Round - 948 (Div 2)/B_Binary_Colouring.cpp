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

    vector<int> bit(32);
    for (int i = 0; i < 32; i++)
        bit[i] = (x & (1 << i)) > 0;

    for (int i = 0, j; i < 32;)
    {
        if (!bit[i])
        {
            i++;
            continue;
        }

        j = i + 1;
        while (bit[j])
            bit[j++] = 0;

        if (j > i + 1)
            bit[i] = -1, bit[j] = 1;
        i = j;
    }

    cout << 32 << endl;
    for (int it : bit)
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