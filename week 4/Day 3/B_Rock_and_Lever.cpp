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

int kthBitSet(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int bit[33] = {0};
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int bitSet = kthBitSet(arr[i]);
        ans += bit[bitSet];
        bit[bitSet] += 1;
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
