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
    int n, k;
    cin >> n >> k;

    int ans;
    if ((n + 1) / 2 >= k)
    {
        ans = 1, k--;
        while (k--)
            ans += 2;
    }
    else
    {
        vector<int> preCalc;
        int i = 2;
        while (i <= n)
        {
            for (int j = 1; j * i <= n; j += 2)
            {
                    preCalc.push_back(i * j);
            }
            i *= 2;
        }

        int idx = (k - 1 - (n + 1) / 2);
        ans = preCalc[idx];
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
