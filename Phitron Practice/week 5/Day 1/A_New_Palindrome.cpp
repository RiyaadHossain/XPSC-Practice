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

    vector<int> freq(26);
    for (int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;

    int occ = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 1)
            occ++;
    }

    cout << (occ > 1 ? ye : no);
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
