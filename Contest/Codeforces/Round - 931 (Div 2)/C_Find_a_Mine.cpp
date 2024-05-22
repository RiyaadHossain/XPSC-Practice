#include <bits/stdc++.h>
using namespace std;

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

int query(int x, int y)
{
    cout << "? " << x << ' ' << y << '\n';
    int d;
    cin >> d;
    return d;
}

void print(int x, int y)
{
    cout << "! " << x << " " << y << '\n';
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int d1 = query(1, 1);

    int xCor = (1 + d1) - n;
    int yCor = (1 + d1) - m;
    xCor = max(0ll, xCor), yCor = max(0ll, yCor);

    int x1 = (1 + d1) - xCor, y1 = 1 + xCor;
    int x2 = 1 + yCor, y2 = (1 + d1) - yCor;

    int d2 = query(x1, y1), d3 = query(x2, y2);
    x1 -= (d2 / 2), y1 += (d2 / 2);
    x2 += (d3 / 2), y2 -= (d3 / 2);

    if (query(x1, y1) == 0)
        print(x1, y1);
    else
        print(x2, y2);
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
