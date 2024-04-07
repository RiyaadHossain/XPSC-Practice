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

bool check(int n, int m)
{
    if (n == m)
        return 1;

    if (n % 3)
        return 0;

    return check(n / 3, m) || check(2 * n / 3, m);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    cout << (check(n, m) ? ye : no);
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
