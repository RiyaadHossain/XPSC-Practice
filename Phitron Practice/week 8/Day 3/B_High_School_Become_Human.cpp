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
    int x, y;
    cin >> x >> y;

    if (x == y || (min(x, y) == 2 && max(x, y) == 4))
    {
        cout << "=";
    }
    else if (x == 1)
    {
        cout << '<';
    }
    else if (y == 1)
    {
        cout << '>';
    }
    else if (x == 2 && y == 3)
    {
        cout << '<';
    }
    else if (y == 2 && x == 3)
    {
        cout << '>';
    }
    else if (x < y)
    {
        cout << '>';
    }
    else
    {
        cout << '<';
    }
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
