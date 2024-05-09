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
    int n, q;
    cin >> n >> q;

    int num;
    map<int, pii> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (!mpp.count(num))
            mpp[num] = {i, i};
        else
            mpp[num].second = i;
    }

    int a, b;
    while (q--)
    {
        cin >> a >> b;

        if (mpp.count(a) && mpp.count(b) && mpp[a].first <= mpp[b].second)
            cout << ye;
        else
            cout << no;
        cout << '\n';
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
    }

    return 0;
}
