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

int rightmostBit(int x)
{
    return log2(x & -x);
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    int odd = 0, even = 0, rightSetBit = 32;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] & 1)
            odd++;
        else
            even++;

        rightSetBit = min(rightSetBit, rightmostBit(arr[i]));
    }

    int ans = even;
    if (odd == 0)
        ans += (rightSetBit - 1);

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
