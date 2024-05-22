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

    int last = -1;
    int lastEven[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] % 2 == 0)
            last = i;
        lastEven[i] = last;
    }

    int ans = 0;
    bool fastOdd = 1;
    for (int i = 0; i < n; i++)
    {
        int val;
        if (arr[i] % 2 == 0)
            ans += (n - i), val = (n - i);
        else if (fastOdd)
            ans += (n - i), fastOdd = 0, val = (n - i);
        else if (lastEven[i] != -1)
            ans += (n - lastEven[i]), val = (n - lastEven[i]);
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
