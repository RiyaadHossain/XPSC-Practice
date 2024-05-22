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

    sort(arr, arr + n);

    int sub = 0;
    bool win = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] -= sub;
        if (arr[i] == 1)
            win ^= 1, sub += arr[i];
        else if(arr[i] > 0)
        {
            win ^= 1;
            break;
        }
    }

    cout << (win ? "Alice" : "Bob");
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
