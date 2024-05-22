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

    vector<string> strings(n);
    map<string, int> mpp;
    for (int i = 0; i < n; i++)
        cin >> strings[i], mpp[strings[i]]++;

    string result;
    for (int i = 0; i < n; i++)
    {
        bool added = 0;
        for (int j = 1; j < strings[i].size(); j++)
        {
            if (mpp[strings[i].substr(0, j)] && mpp[strings[i].substr(j)])
            {
                added = 1;
                result.push_back('1');
                break;
            }
        }

        if (!added)
            result.push_back('0');
    }

    for (char it : result)
        cout << it;
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
