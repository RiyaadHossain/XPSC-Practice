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

    bool flag = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int bits = 0; bits < n; bits++)
        {
            if (i & (1 << bits))
                sum += arr[bits];
            else
                sum -= arr[bits];
        }
        
        if (sum % 360 == 0)
        {
            flag = 1;
            break;
        }
    }

    cout << (flag ? ye : no);
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
