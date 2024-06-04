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

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int last = 1, idx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int x = __gcd(arr[i], arr[i + 1]);
        if (x < last)
        {
            idx = i;
            break;
        }
        last = x;
    }

    auto check = [&](int id)
    {
        int t = 0;
        vector<int> tmp(n - 1);
        for (int i = 0; i < n; i++)
        {
            if (id != i)
                tmp[t++] = arr[i];
        }

        int last = 1, idx = -1;
        for (int i = 0; i < n - 2; i++)
        {
            int x = __gcd(tmp[i], tmp[i + 1]);
            if (x < last)
                return false;
            last = x;
        }

        return true;
    };

    if (idx == -1)
        ye;
    else if (check(idx) || check(idx - 1) || check(idx + 1))
        ye;
    else
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