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

bool isOne(vector<vector<char>> &grid, int i, int j)
{
    return grid[i][j] == '1';
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }

    int i = 0;
    int ans = 0;
    while (i < n / 2)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            int zeros = 0, ones = 0;
            if (isOne(grid, i, j))
                ones++;
            else
                zeros++;
            if (isOne(grid, j, n - i - 1))
                ones++;
            else
                zeros++;
            if (isOne(grid, n - i - 1, n - j - 1))
                ones++;
            else
                zeros++;
            if (isOne(grid, n - j - 1, i))
                ones++;
            else
                zeros++;
            ans += min(zeros, ones);
        }
        i++;
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
