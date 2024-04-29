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

    sort(arr, arr + n);

    auto ok = [&](int key)
    {
        int cnt = 0;
        int first = arr[0], last, diff;
        for (int i = 0; i < n; i++)
        {
            last = arr[i];
            diff = (last + 1 - first) / 2;
            if (diff > key)
                cnt++, first = arr[i];
        }

        return cnt < 3;
    };

    int ans = 0;
    int left = 0, right = 1e9, mid;
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

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
