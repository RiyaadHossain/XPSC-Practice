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

    ll arr[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += abs(arr[i]);

    int op = 0;
    int i = 0;
    while (i < n)
    {
        if (arr[i] >= 0)
        {
            i++;
            continue;
        }
        op++;
        while (i < n && arr[i] <= 0)
            i++;
    }

    cout << sum << " " << op;
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
