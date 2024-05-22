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

    int n = str.size();
    vector<pii> path;

    int firstCh = str[0] - 'a', lastCh = str[n - 1] - 'a';

    if (firstCh < lastCh)
    {
        for (int i = 1; i < n - 1; i++)
        {
            int curr = str[i] - 'a';
            if (firstCh <= curr && curr <= lastCh)
                path.push_back({curr, i + 1});
        }

        sort(path.begin(), path.end());
    }
    else
    {
        for (int i = 1; i < n - 1; i++)
        {
            int curr = str[i] - 'a';
            if (firstCh >= curr && curr >= lastCh)
                path.push_back({curr, i + 1});
        }

        sort(path.begin(), path.end(), greater<pii>());
    }

    int cost = abs(firstCh - lastCh), pathLen = path.size() + 2;
    cout << cost << " " << pathLen << endl;
    cout << 1 << " ";
    for (pii it : path)
        cout << it.second << " ";

    cout << n << " ";
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
