#include <bits/stdc++.h>
using namespace std;

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

bool notOneBit(int x)
{
    return !(x & (x - 1));
}

void solve()
{
    int n, l, r, x;
    cin >> n >> l >> r >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int subsets = 1 << n;
    int ans = 0;
    for (int i = 2; i < subsets; i++)
    {
        if (notOneBit(i))
            continue;

        ll total = 0;
        int mn = INT_MAX, mx = 0;
        for (int bits = 0; bits < n; bits++)
        {
            if (i & (1 << bits))
            {
                total += arr[bits];
                mx = max(mx, arr[bits]), mn = min(mn, arr[bits]);
            }
        }

        if (total >= l && r >= total && (mx - mn) >= x)
            ans++;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
