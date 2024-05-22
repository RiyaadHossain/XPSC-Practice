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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto ok = [&](int key)
    {
        multiset<int> ml;
        for (int i = 0; i < n; i++)
            ml.insert(arr[i]);

        int req;
        for (int k = 1; k <= key; k++)
        {
            req = key - k + 1;

            auto it = ml.upper_bound(req);
            if (it == ml.begin() || ml.empty())
                return 0;

            ml.erase(--it);

            if (ml.empty())
                break;

            it = ml.begin();
            ml.insert(*it + req);
            ml.erase(it);
        }

        return 1;
    };

    int ans = 0;
    int left = 0, right = n, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
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
