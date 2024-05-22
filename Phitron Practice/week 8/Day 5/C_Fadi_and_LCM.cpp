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
    int x;
    cin >> x;

    int ans;
    for (int i = 1; i * i <= x; i++)
    {
        if (x % i == 0 && lcm(i, x / i) == x)
            ans = i;
    }

    cout << ans << " " << x / ans;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
