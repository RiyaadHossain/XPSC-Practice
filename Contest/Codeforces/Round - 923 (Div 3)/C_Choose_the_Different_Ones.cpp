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
    int n, m, k;
    cin >> n >> m >> k;

    set<int> st1, st2;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        if (val <= k)
            st1.insert(val);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        if (val <= k)
            st2.insert(val);
    }

    if (st1.size() < (k / 2) || st2.size() < (k / 2))
    {
        cout << no;
        return;
    }

    vector<int> track(k + 1);
    for (int it : st1)
        track[it]++;
    for (int it : st2)
        track[it]++;

    for (int i = 1; i <= k; i++)
    {
        if (track[i] == 0)
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
