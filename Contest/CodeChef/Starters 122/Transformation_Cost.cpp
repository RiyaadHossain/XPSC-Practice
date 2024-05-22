#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

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

    int tmp = n;
    int cnt = -1;

    bool one1 = 0, zero = 0, one2 = 0;
    while (tmp)
    {
        if (tmp & 1)
            one1 = 1;
        if (one1 && (tmp & 1) == 0)
            zero = 1;
        if (zero && (tmp & 1))
            one2 = 1;

        tmp >>= 1;
        cnt++;
    }

    if (!one2)
    {
        cout << 0;
        return;
    }

    int ans = 0, curr;
    tmp = n;
    while (cnt)
    {
        curr = (1 << cnt);
        ans += curr;
        if ((tmp & curr) == 0)
            break;
        cnt--;
    }

    cout << ans - n;
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
