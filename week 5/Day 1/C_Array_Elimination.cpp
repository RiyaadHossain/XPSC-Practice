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

    vector<int> bitCnt(33);
    int curr, cnt;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        curr = arr[i];
        while (curr)
        {
            cnt++;
            if (curr & 1)
                bitCnt[cnt]++;
            curr >>= 1;
        }
    }

    bool ok;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ok = 0;
        for (int j = 1; j <= 32; j++)
        {
            if (bitCnt[j] % i != 0)
                break;

            if (j == 32)
                ok = 1;
        }
        if (ok)
            ans.push_back(i);
    }

    for (int it : ans)
        cout << it << " ";
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
