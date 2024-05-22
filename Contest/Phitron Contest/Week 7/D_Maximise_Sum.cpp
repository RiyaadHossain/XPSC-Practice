#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
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

    int preMx[n];
    preMx[0] = arr[0];
    for (int i = 1; i < n; i++)
        preMx[i] = max(preMx[i - 1], arr[i]);

    int suffMx[n];
    suffMx[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suffMx[i] = max(suffMx[i + 1], arr[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += min(preMx[i], suffMx[i]);

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
