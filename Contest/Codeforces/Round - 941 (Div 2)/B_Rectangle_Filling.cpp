#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool check(vector<vector<char>> grid, int n, int m, char color)
{

    bool firstRow = 0, lastRow = 0, firstCol = 0, lastCol = 0;
    for (int i = 0; i < m; i++)
    {
        firstRow = firstRow || (grid[0][i] == color);
        lastRow = lastRow || (grid[n - 1][i] == color);
    }

    for (int i = 0; i < n; i++)
    {
        firstCol = firstCol || (grid[i][0] == color);
        lastCol = lastCol || (grid[i][m - 1] == color);
    }

    return (firstRow && lastRow && firstCol && lastCol);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    bool ans = check(grid, n, m, 'W') || check(grid, n, m, 'B');

    cout << (ans ? ye : no);
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
