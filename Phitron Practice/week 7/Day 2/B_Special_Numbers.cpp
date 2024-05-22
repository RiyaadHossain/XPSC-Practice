/*
  Author: Riyad Hossain
  CodeForces: https://codeforces.com/profile/Riyad_Hossain
  CodeChef: https://www.codechef.com/users/riyadhossain
*/

#include <bits/stdc++.h>
using namespace std;

// Defination
#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll llinf = 1e18;

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second
#define ins insert
#define lb lower_bound // First element NOT LESS than val
#define ub upper_bound // First element GREATER than val

// Loop mechanisms
#define forr(i, a, b) for (int i = (a); i < (b); i++)
#define rforr(i, a, b) for (int i = (a); i >= (b); i--)
#define rep(i, n) For(i, 0, (n))
#define each(x, a) for (auto &x : a)
#define forEach(x, a) for (auto x = a.begin(); x != a.end(); ++x)

ll powermod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    while (k > 0)
    {
        if (k == 1 || k == 2)
        {
            ans += (k == 1 ? 1 : n), k = 0;
            ans %= mod;
            continue;
        }

        int exp = floor(log2(k));
        ans += powermod(n, exp, mod);
        k -= pow(2, exp);
        ans %= mod;
    }

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
        cout << endl;
    }

    return 0;
}
