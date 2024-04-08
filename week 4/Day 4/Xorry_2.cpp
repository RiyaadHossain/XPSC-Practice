#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    int cnt = -1, tmp = n;
    while (tmp)
    {
        cnt++;
        tmp >>= 1;
    }

    int b = 1 << cnt;
    int a = n ^ b;

    int ans = 1;
    while (a)
    {
        if((a&1)== 0)
            ans *= 2;
        a >>= 1;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
