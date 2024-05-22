#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
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

    if (n == 2 && arr[0] > arr[1])
    {
        cout << no;
        return;
    }

    if (n == 3)
    {
        if (arr[0] > arr[2])
            swap(arr[0], arr[2]);

        if (arr[1] > arr[2] || arr[1] < arr[0])
        {
            cout << no;
            return;
        }
    }

    cout << ye;
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
