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
    string str;
    cin >> str;

    int n = str.size();

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (str[i] == '0' && str[i - 1] == '1')
            ans++;
        if (str[i] == '1' && str[i - 1] == '0')
            ans++;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == '0' && str[i + 1] == '1')
        {
            ans--;
            break;
        }
    }

    cout << ans;
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
