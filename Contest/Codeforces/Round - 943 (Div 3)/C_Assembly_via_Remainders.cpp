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

    int val;
    vector<int> result(n);
    for (int i = 1; i < n; i++)
    {
        cin >> val;
        if (i == 1 && val % 2)
            result[0] = 501;
        else if (i == 1)
            result[0] = 501;

        result[i] = (result[i - 1]) + val;
    }

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
