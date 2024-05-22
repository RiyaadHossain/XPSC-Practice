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
    int n, k, x;
    cin >> n >> k >> x;

    int ans = INT_MIN;
    if (n == k)
        ans = 0;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, greater<int>());
    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int sum = prefix[n - 1], carry = 0, curr, idx;
    ans = max(ans, sum - (prefix[x - 1] * 2));
    for (int i = 0; i < k; i++)
    {
        carry += arr[i];
        sum -= arr[i];
        idx = min(i + x, n - 1);
        curr = sum - ((prefix[idx] - carry) * 2);
        ans = max(ans, curr);
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
