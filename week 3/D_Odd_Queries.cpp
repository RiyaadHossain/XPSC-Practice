#include <bits/stdc++.h>
using namespace std;
#define int long long

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int prefix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int rangeSum = prefix[r - 1] - (l == 1 ? 0 : prefix[l - 2]);
        int newSum = (prefix[n - 1] - rangeSum) + ((r + 1 - l) * k);
        cout << (newSum % 2 == 1 ? ye : no);

        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
