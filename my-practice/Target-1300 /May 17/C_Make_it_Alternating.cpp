#include <bits/stdc++.h>
using namespace std;

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
const int mod = 998244353;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    string s;
    cin >> s;

    int n = sz(s);

    char ch = s[0];
    int cnt = 1, len = 0, ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ch)
            cnt++, len++;
        else
        {
            ans = (ans * cnt) % mod;
            cnt = 1, ch = (ch == '1' ? '0' : '1');
        }
    }

    ans = (ans * cnt) % mod;

    int fac = 1;
    for (int i = 2; i <= len; i++)
        fac = (fac * i) % mod;

    ans = (ans * fac) % mod;
    cout << len << " " << ans;
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