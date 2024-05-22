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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a > b)
        swap(a, b);

    if (a < c && a < d && b > c && b > d)
    {
        no;
        return;
    }

    for (int i = a; i <= b; i++)
    {
        if (i == c || i == d)
        {
            ye;
            return;
        }
    }

    no;
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
