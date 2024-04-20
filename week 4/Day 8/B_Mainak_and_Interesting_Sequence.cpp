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
    int n, m;
    cin >> n >> m;

    if (n > m)
    {
        cout << no;
        return;
    }

    if (n == m)
    {
        cout << ye << endl;
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        return;
    }

    vector<int> result;
    for (int i = 0; i < (n - (n % 2 ? 1 : 2)); i++)
        result.push_back(1), m--;

    if ((m & 1))
    {
        if (n % 2 == 0)
        {
            cout << no;
            return;
        }

        result.push_back(m);
    }
    else
    {
        if (n % 2)
            result.push_back(m);
        else
        {
            result.push_back(m / 2);
            result.push_back(m / 2);
        }
    }

    cout << ye << endl;
    for (int it : result)
        cout << it << " ";
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
