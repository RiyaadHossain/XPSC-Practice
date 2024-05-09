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
    int n, t;
    cin >> n >> t;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto ok = [&](int mid)
    {
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += (mid / arr[i]);
            if (total >= t)
                return 1;
        }

        return 0;
    };

    int ans = 0;
    int left = 0, right = 1e18, mid, totalPod;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid))
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
