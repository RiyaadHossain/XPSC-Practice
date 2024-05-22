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

    bool ok1 = 0, ok2 = 0;
    int i1, i2, i3;
    for (int i = 1; i < n - 1; i++)
    {
        ok1 = 0, ok2 = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < arr[i])
            {
                i1 = j + 1, ok1 = 1;
                break;
            }
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                i3 = j + 1, ok2 = 1;
                break;
            }
        }

        if (ok1 && ok2)
        {
            i2 = i + 1;
            break;
        }
    }

    if (ok1 && ok2)
        cout << ye << endl
             << i1 << " " << i2 << " " << i3;
    else
        cout << no;
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
