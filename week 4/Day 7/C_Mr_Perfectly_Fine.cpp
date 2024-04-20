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

    ll skill1 = INT_MAX, skill2 = INT_MAX;

    ll m;
    string skills;
    ll ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        cin >> skills;

        if (skills[0] == '1')
            skill1 = min(skill1, m);
        if (skills[1] == '1')
            skill2 = min(skill2, m);

        if (skills == "11")
            ans = min(ans, m);
    }

    if (skill1 == INT_MAX || skill2 == INT_MAX)
    {
        cout << -1;
        return;
    }

    cout << (ans < (skill1 + skill2) ? ans : skill1 + skill2);
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
