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

    int ans = 1e9, curr, coins;

    for (int ones = 0; ones <= 2; ones++)
    {
        for (int threes = 0; threes <= 1; threes++)
        {
            for (int sixs = 0; sixs <= 4; sixs++)
            {
                for (int tens = 0; tens <= 2; tens++)
                {
                    curr = 1 * ones + 3 * threes + 6 * sixs + 10 * tens;
                    coins = ones + threes + sixs + tens;
                    if (curr <= n && (n - curr) % 15 == 0)
                        ans = min(ans, coins + ((n - curr) / 15));
                }
            }
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
