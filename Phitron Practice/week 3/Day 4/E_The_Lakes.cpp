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

int n, m;
vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

int dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j)
{
    int sum = grid[i][j];
    vis[i][j] = 1;
    for (pii d : dir)
    {
        int ci = i + d.first, cj = j + d.second;
        if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != 0)
            sum += dfs(grid, vis, ci, cj);
    }
    return sum;
}

void solve()
{
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (vis[i][j] == 0 && grid[i][j] != 0)
                ans = max(ans, dfs(grid, vis, i, j));
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
