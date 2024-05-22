#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int l, r;
    cin >> l >> r;

    ye;
    for (int i = l; i <= r; i += 2)
    {
        cout << i << " " << i + 1 << endl;
    }
}

int32_t main()
{
    fastio;

        solve();
        cout << '\n';

    return 0;
}
