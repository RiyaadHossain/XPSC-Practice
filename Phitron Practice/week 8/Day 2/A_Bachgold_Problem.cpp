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

    cout << n / 2 << endl;

    for (int i = 1; i < n/2; i++)
        cout << 2 << " ";

    if (n % 2)
        cout << 3;
    else
        cout << 2;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
