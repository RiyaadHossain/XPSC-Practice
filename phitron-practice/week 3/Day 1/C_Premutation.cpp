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

    vector<vector<int>> numbers(n + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            int num;
            cin >> num;
            numbers[num].push_back(j + 1);
        }
    }

    for (int i = 1; i <= n; i++)
        sort(numbers[i].begin(), numbers[i].end());

    int ans[n + 1];
    for (int i = 1; i <= n; i++)
    {
        if (numbers[i][n - 2] != n - 1 || numbers[i][n - 2] != numbers[i][0])
            ans[numbers[i][n - 2]] = i;
        else
            ans[n] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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
