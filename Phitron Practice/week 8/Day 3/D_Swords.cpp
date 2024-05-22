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

    int g = 0, mx = *max_element(arr, arr + n);
    for (int i = 0; i < n; i++)
        g = __gcd(g, mx - arr[i]);

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (mx - arr[i]) / g;

    cout << ans << " " << g;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
