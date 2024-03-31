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

    int num;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        mpp[num]++;
    }

    int ans = 0;
    auto it = mpp.begin();
    int curr = it->first;
    int lastCnt = it->second;
    for (; it != mpp.end(); it++)
    {
        if (curr + 1 == it->first)
            ans += max(0, it->second - lastCnt);
        else
            ans += it->second;

        curr = it->first, lastCnt = it->second;
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
