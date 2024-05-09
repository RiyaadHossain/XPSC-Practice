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

    int len = (n * (n - 1)) / 2;
    int last = 0;
    int arr[len];
    map<int, int> mpp;
    for (int i = 0; i < len; i++)
        cin >> arr[i], mpp[arr[i]]++, last = max(last, arr[i]);

    vector<int> ans;
    while (!mpp.empty())
    {
        len = n - 1 - ans.size();

        auto it = mpp.begin();
        ans.push_back(it->first), it->second -= len;
        if (it->second <= 0)
            mpp.erase(it);
    }
    ans.push_back(last);

    for (int it : ans)
        cout << it << " ";
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
