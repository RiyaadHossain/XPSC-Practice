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

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= min(n, 22ll); i++)
    {
        bool ok = 0;
        for (int j = 2; j <= i + 1; j++)
        {
            if (arr[i] % j)
            {
                ok = 1;
                break;
            }
        }
        if (!ok)
        {
            no;
            return;
        }
    }

    ye;
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
