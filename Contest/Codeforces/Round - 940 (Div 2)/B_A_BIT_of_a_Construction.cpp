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

int setBit(int x)
{
    int cnt = -1;
    while (x)
    {
        cnt++;
        x >>= 1;
    }

    return cnt;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        cout << k;
        return;
    }

    int allSet = (1 << setBit(k)) - 1;
    cout << allSet << " " << k - allSet << " ";

    for (int i = 3; i <= n; i++)
        cout << 0 << " ";
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
