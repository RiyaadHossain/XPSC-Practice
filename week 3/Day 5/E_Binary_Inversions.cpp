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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int cnt = 0;
    int oneCnt[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            cnt++;
        oneCnt[i] = cnt;
    }

    cnt = 0;
    int zeroCnt[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
            cnt++;
        zeroCnt[i] = cnt;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == 1)
            sum += zeroCnt[i];

    ll ans = sum, tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = sum;
        if (arr[i] == 1)
            tmp -= zeroCnt[i], tmp += (oneCnt[i] - 1);
        else
            tmp -= oneCnt[i], tmp += (zeroCnt[i] - 1);
        ans = max(ans, tmp);
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
