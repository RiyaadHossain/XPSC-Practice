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
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 1, right = 1e10, mid, ans;
    while (left <= right)
    {
        mid = (left + right) / 2;

        int water = 0;
        for (int i = 0; i < n; i++)
        {
            if (mid > arr[i])
                water += (mid - arr[i]);
        }

        if (water <= x)
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
