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
    string str1, str2;
    cin >> str1 >> str2;

    int n = str1.size(), m = str2.size();
    map<string, int> mpp;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
            mpp[str1.substr(i, j)]++;
    }

    int ans = 0;
    string curr;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= m - i; j++)
        {
            curr = str2.substr(i, j);

            if (mpp.find(curr) != mpp.end())
                ans = max(ans, int(curr.size() * 2));
        }
    }

    cout << n + m - ans;
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
