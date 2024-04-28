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

    int arr[k];
    for (int i = 0; i < k; i++)
        cin >> arr[i];

    sort(arr, arr + k);

    int ans = k, cat = 0;
    for (int i = k - 1; i >= 0; i--)
    {
        if (cat < arr[i])
            cat += (n - arr[i]);
        else
        {
            ans = k - 1 - i;
            break;
        }
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
