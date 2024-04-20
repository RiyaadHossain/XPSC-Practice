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
    int l, r;
    cin >> l >> r;

    if ((r - l) + 1 == 1)
    {
        cout << -1;
        return;
    }

    if ((r - l) + 1 == 2)
    {
        cout << r << " " << l;
        return;
    }

    if (!(r % 2) && !(l % 2))
    {
        cout << -1;
        return;
    }

    int toggle = 1;
    bool oddLen = ((r - l) + 1) % 2;
    for (int i = l; i <= r - (oddLen ? 3 : 0); i++)
    {
        if (toggle)
            cout << i + 1 << " ";
        else
            cout << i - 1 << " ";
        toggle ^= 1;
    }

    if (oddLen)
        cout << r << " " << r - 2 << " " << r - 1;
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
