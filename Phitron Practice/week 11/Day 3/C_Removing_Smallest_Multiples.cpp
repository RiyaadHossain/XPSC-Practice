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

int getSpf(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return i;
    }

    return num;
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<bool> sieve(n + 1);
    for (int i = 0; i < n; i++)
        if (s[i] == '1')
            sieve[i + 1] = 1;

    vector<int> cost(n + 1);
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j += i)
        {
            if (sieve[j])
                break;
            cost[j] = i;
        }
    }

    int ans = 0;
    for (int it : cost)
        ans += it;

    cout << ans;
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