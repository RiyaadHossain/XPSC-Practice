#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

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

    if (m == 1)
        cout << 0 << endl;
    else
        cout << min(n + 1, m) << endl;

    for (int i = 0; i < min(m - 1, n); i++)
    {
        for (int j = 0; j < m; j++)
            cout << (i + j) % m << " ";
        cout << endl;
    }

    if (m < n + 1)
    {
        for (int i = m - 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << j << " ";
            cout << endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}