#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
#define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forEach(x, ds) for (auto &x : ds)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)

// Shortcut Functions
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcountll(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Constant Varialbes
const int inf = 1e9;
const int llinf = 1e18;
const int mod = 1e9 + 7;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> board(n, vector<char>(m));
    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
                cin >>
            board[i][j];
    }

    vector<vector<bool>> added(n, vector<bool>(m, 0));
    auto check = [&](int row, int col) -> bool
    {
        if (row + k >= n || col + k * 2 >= m)
            return 0;

        vpi cells = {{row, col}};
        forr(i, 1, k)
        {
            if (board[row + i][col + i] != '*')
                return 0;
            cells.pb({row + i, col + i});
        }

        row += k, col += k;
        forr(i, 1, k)
        {
            if (board[row - i][col + i] != '*')
                return 0;
            cells.pb({row - i, col + i});
        }

        for (auto [x, y] : cells)
            added[x][y] = 1;
        return 1;
    };

    forr(i, 0, n - 1)
    {
        forr(j, 0, m - 1)
        {
            if (board[i][j] == '*')
            {
                if (!check(i, j) && !added[i][j])
                {
                    // printsp(i), println(j);
                    // forr(i, 0, n - 1)
                    // {
                    //     forr(j, 0, m - 1)
                    //         printsp(added[i][j]);
                    //     println(" ");
                    // }
                    no;
                    return;
                }
            }
        }
    }

    ye;
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
        cout << '\n';
    }

    return 0;
}