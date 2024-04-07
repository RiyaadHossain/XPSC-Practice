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

    int n, c;
    cin >> n >> c;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int left = 1, right = 1e9;
    while (left <= right)
    {
        int total = 0;
        int mid = (left + right) / 2;
        for (int i = 0; i < n; i++)
        {
            total += (arr[i] + 2 * mid) * (arr[i] + 2 * mid);
            if (total > c)
                break;
        }

        if (total == c)
        {
            cout << mid;
            break;
        }

        if (total > c)
            right = mid - 1;
        else
            left = mid + 1;
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
