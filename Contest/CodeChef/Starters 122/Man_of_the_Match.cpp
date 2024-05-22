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
    int player = 1;
    int mom, maxScore = 0;
    int runs, wickets, curr;
    while (player <= 22)
    {
        cin >> runs >> wickets;
        curr = runs * 1 + wickets * 20;
        if (curr > maxScore)
            mom = player, maxScore = curr;

        player++;
    }

    cout << mom;
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
