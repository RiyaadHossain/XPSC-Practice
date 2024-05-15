#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
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

    vector<vector<int>> freq(1001);
    int x;
    for (int i = 1; i <= n; i++)
        cin >> x, freq[x].push_back(i);

    int ans = -1;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = i; j <= 1000; j++)
        {
            if (freq[i].size() && freq[j].size() && __gcd(i, j) == 1)
                ans = max(ans, freq[i].back() + freq[j].back());
        }
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
