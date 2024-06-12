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
    int a, b, r;
    cin >> a >> b >> r;

    if (a < b)
        swap(a, b);

    int maxBit = 62, firstBit = 1;
    for (int i = maxBit; i >= 0; i--)
    {
        int curr = (1ll << i);
        int bit_a = (a & curr);
        int bit_b = (b & curr);

        if (bit_a && !bit_b)
        {
            if (firstBit)
            {
                firstBit = 0;
                continue;
            }

            if (curr <= r)
                a ^= curr, b ^= curr, r -= curr;
        }
    }

    int ans = a - b;
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