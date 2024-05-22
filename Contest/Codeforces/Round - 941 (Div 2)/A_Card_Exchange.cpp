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
    vector<int> track(101, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i], track[arr[i]]++;

    for (int i = 1; i <= 100; i++)
    {
        if (track[i] >= k)
        {
            cout << k - 1;
            return;
        }
    }

    cout << n;
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
