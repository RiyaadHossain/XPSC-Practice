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

    string str;
    cin >> str;

    int f, l;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'B')
        {
            f = i;
            break;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == 'B')
        {
            l = i;
            break;
        }
    }

    cout << (l + 1 - f);
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
