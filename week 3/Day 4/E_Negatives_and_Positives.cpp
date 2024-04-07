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
    int cnt = 0, sum = 0, mn = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i], sum += abs(arr[i]);
        if (arr[i] < 0)
            cnt++;
        mn = min(mn, abs(arr[i]));
    }

    if (cnt & 1)
        sum -= 2 * mn;

    cout << sum;
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
