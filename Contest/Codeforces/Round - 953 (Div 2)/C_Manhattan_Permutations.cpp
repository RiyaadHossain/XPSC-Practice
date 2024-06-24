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

int sumOfEvens(int n)
{
    int k = n / 2;
    return k * (k + 1) * 2;
}

int sumOfOdds(int n)
{
    int k = (n + 1) / 2;
    return k * k * 2;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int mx = sumOfOdds(n - 1);
    if (n % 2)
        mx = sumOfEvens(n - 1);

    if (k % 2 || mx < k)
    {
        no;
        return;
    }

    ye;
    cout << endl;

    vi ans(n);
    for (int i = 0; i < n; i++)
        ans[i] = i + 1;

    k = max(k, 1ll);
    for (int i = 0; i < n / 2; i++)
    {
        int a = ans[i];
        int b = min(n - i, a + k / 2);
        if (k > 0)
        {
            swap(ans[i], ans[b - 1]);
            k -= (abs(a - b) * 2);
        }
    }

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