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
    int n, m;
    cin >> n >> m;

    int grid[n][m];

    int cnt = 1;
    int row = 2;
    for (int i = 1; i <= n / 2; i++)
    {
        for (int j = 0; j < m; j++)
            grid[row][j] = cnt++;
        row += 2;
    }

    row = 1;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        for (int j = 0; j < m; j++)
            grid[row][j] = cnt++;
        row += 2;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
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
