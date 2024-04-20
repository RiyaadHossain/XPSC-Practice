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

void solve()
{
    int n;
    cin >> n;

    int allOne = 0xFFFFFFFF;

    vector<int> arr(n);
    int AND = allOne;
    for (int i = 0; i < n; i++)
        cin >> arr[i], AND &= arr[i];

    if (AND > 0)
    {
        cout << 1;
        return;
    }

    ll ans = 0;
    int curr = allOne;
    for (int i = 0; i < n; i++)
    {
        curr &= arr[i];
        if (curr == AND)
            ans++, curr = allOne;
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