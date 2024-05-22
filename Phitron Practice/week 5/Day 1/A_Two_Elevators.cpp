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
    ll a, b, c;
    cin >> a >> b >> c;

    ll first = a - 1;
    ll second;
    if (b > c)
        second = b - 1;
    else
        second = (c - b) + (c - 1);

    if (first < second)
        cout << 1;
    else if (second < first)
        cout << 2;
    else
        cout << 3;
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
