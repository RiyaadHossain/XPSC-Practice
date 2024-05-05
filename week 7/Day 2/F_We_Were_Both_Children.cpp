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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LLINF = 1e18;

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
#define rep(i, n) forr(i, 0, (n))
#define each(x, a) for (auto &x : a)
#define forEach(x, a) for (auto x = a.begin(); x != a.end(); ++x)

void solve()
{
    int n;
    cin >> n;

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x <= n)
            cnt[x]++;
    }

    vector<int> mx(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            mx[j] += cnt[i];
    }

    cout << *max_element(all(mx));
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
