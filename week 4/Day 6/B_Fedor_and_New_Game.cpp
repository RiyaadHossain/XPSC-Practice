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

int countSetBits(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x & 1)
            cnt++;
        x >>= 1;
    }

    return cnt;
}

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int arr[m];
    for (int i = 0; i < m; i++)
        cin >> arr[i];

    int fedor;
    cin >> fedor;

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int num = fedor ^ arr[i];
        int diff = countSetBits(num);
        if (diff <= k)
            ans++;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
