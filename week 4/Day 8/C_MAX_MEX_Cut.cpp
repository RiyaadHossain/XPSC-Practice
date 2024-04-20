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

    string table1, table2;
    cin >> table1 >> table2;

    int ans = 0;
    int i = 0, one, zero;
    while (i < n)
    {
        one = 0, zero = 0;
        one += (table1[i] == '1') + (table2[i] == '1');
        zero += (table1[i] == '0') + (table2[i] == '0');

        if (one && zero)
        {
            ans += 2;
            i++;
        }

        if (!one && zero)
        {
            if (i + 1 < n)
                one += (table1[i + 1] == '1') + (table2[i + 1] == '1');

            if (one == 2)
                ans += 2, i += 2;
            else
                ans++, i++;
        }

        if (one && !zero)
        {
            while (i < n && !zero)
                zero += (table1[i] == '0') + (table2[i] == '0'), i++;
            ans += (zero ? 2 : 0);
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