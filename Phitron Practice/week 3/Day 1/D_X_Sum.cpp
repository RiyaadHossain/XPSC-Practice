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
    int n, m;
    cin >> n >> m;

    int grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ll attack = grid[i][j];

            int a = i - 1, b = j - 1;
            while (a >= 0 && b >= 0)
                attack += grid[a][b], a--, b--;
            a = i + 1, b = j + 1;
            while (a < n && b < m)
                attack += grid[a][b], a++, b++;
            a = i - 1, b = j + 1;
            while (a >= 0 && b < m)
                attack += grid[a][b], a--, b++;
            a = i + 1, b = j - 1;
            while (a < n && b >= 0)
                attack += grid[a][b], a++, b--;

            ans = max(ans, attack);
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
