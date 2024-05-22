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
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<pii> misMatch;
    for (int i = 0; i < n - 1; i+=2)
    {
        if (str[i] != str[i + 1])
        {
            if (str[i] == '1')
                misMatch.push_back({i, i + 1});
            else
                misMatch.push_back({i + 1, i});
        }
    }

    cout << misMatch.size() << endl;

    int toggle = 1;
    for (pii it : misMatch)
    {
        if (toggle)
            cout << it.first + 1 << " ";
        else
            cout << it.second + 1 << " ";
        toggle ^= 1;
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
        cout << '\n';
    }

    return 0;
}
