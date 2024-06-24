#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long
#define print(...) cout << (__VA_ARGS__)
#define println(...) cout << (__VA_ARGS__) << '\n'

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    bool f = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
            cnt += (board[i][j] != '.');
        f |= (cnt % 2);
    }

    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (board[i][j] != '.');
        f |= (cnt % 2);
    }

    if (f)
    {
        println(-1);
        return;
    }

    vector<vi> ans(n, vi(m, -1));
    for (int i = 0; i < n; i++)
    {
        int c = 0;
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'U')
            {
                ans[i][j] = c;
                ans[i + 1][j] = c ^ 1;
                c ^= 1;
            }
        }
    }

    for (int j = 0; j < m; j++)
    {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (board[i][j] == 'L')
            {
                ans[i][j] = c;
                ans[i ][j+ 1] = c ^ 1;
                c ^= 1;
            }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] == -1)
                print('.');
            if (ans[i][j] == 0)
                print('B');
            if (ans[i][j] == 1)
                print('W');
        }
        cout << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        // cout << '\n';
    }

    return 0;
}