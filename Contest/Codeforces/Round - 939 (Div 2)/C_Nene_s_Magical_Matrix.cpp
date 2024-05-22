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

void solve()
{
    int n;
    cin >> n;

    int sum = 0;
    int tmp = n;
    while (tmp)
    {
        sum += (tmp * ((tmp * 2) - 1));
        tmp--;
    }

    cout << sum << " " << (2 * n) << endl;

    // zigzag operation
    for (int i = 1; i <= n; i++)
    {
        cout << 1 << " " << i << " ";
        for (int j = 1; j <= n; j++)
            cout << j << " ";
        cout << endl;

        cout << 2 << " " << n+1-i << " ";
        for (int j = n; j >= 1; j--)
            cout << j << " ";
        cout << endl;
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
