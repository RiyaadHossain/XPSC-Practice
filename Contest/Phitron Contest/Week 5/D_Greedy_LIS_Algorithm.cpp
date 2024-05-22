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
    int n, x;
    cin >> n >> x;

    if (x == 0)
    {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        return;
    }

    if (x > n - 2)
    {
        cout << -1;
        return;
    }

    int it = n;
    int arr[n + 1];
    for (int i = 1; i <= (n - (x + 1)); i++)
    {
        arr[i] = it;
        it--;
    }

    it = 1;
    for (int i = (n + 1 - (x + 1)); i <= n; i++)
    {
        arr[i] = it;
        it++;
    }

    for (int i = 1; i <= n; i++)
        cout << arr[i] << " ";
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
