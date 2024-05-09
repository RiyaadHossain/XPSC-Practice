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
    string str;
    cin >> str;

    int ans = 0;
    int i = 0;
    while (i < str.size())
    {
        if (i < str.size() && str[i] == '0')
        {
            while (str[i] == '0')
                i++;
            ans++;
            continue;
        }

        if (i < str.size() && str[i] == '1')
        {
            while (str[i] == '1')
                i++;
            continue;
        }
        i++;
    }

    cout << (ans < 2 ? ans : 2);
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
