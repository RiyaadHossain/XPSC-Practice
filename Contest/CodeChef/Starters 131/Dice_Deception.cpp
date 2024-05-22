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

    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];

    sort(arr, arr + n);

    for (int i = 0; i < k; i++)
    {
        if (arr[i] <= 3)
            sum += ((7 - arr[i]) - arr[i]);
    }

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
