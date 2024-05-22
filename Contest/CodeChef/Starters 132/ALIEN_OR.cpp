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
    int n, k;
    cin >> n >> k;

    int i = 0;
    int cnt, bit;
    string str;
    vector<int> track(k);
    while (i < n)
    {
        cin >> str;

        cnt = 0;
        bit = 0;
        for (int j = 0; j < k; j++)
        {
            cnt += (str[j] == '1');
            if (str[j] == '1')
                bit = j;
        }

        if (cnt == 1)
            track[bit] = 1;

        i++;
    }

    for (int it : track)
    {
        if (it == 0)
        {
            cout << no;
            return;
        }
    }

    cout << ye;
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
