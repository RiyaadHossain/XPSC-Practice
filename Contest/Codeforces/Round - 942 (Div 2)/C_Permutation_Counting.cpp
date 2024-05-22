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
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto ok = [&](int score)
    {
        int need = 0, extra = 0;
        int totalCard = score + n - 1;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > totalCard / n)
                extra++;
            if (arr[i] < totalCard / n)
                need += (totalCard / n - arr[i]);
        }

        need += max(totalCard % n - extra, 0LL);
        return need <= k;
    };

    int ans = 0;
    int left = 0, right = 1e18, mid;
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
