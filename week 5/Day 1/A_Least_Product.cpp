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
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        zero += arr[i] == 0;
        neg += arr[i] < 0;
    }

    if (zero || (neg & 1))
        cout << 0;
    else
    {
        cout << 1 << endl;
        cout << 1 << " " << 0;
    }
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
