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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i <= 256; i++)
    {
        int temp[n];
        for (int j = 0; j < n; j++)
            temp[j] = arr[j] ^ i;

        int XOR = 0;
        for (int j = 0; j < n; j++)
            XOR ^= temp[j];

        if (XOR == 0)
        {
            cout << i;
            return;
        }
    }
    cout << -1;
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
