#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n, k;
    cin >> n >> k;

    char arr[n];
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == '1')
            ones++;
    }

    if (ones <= k)
    {
        for (int i = 0; i < n - k; i++)
            cout << '0';

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (ones)
        {
            if (arr[i] == '1' && k)
                cout << '0', k--;
            else
                cout << arr[i];
        }
        else
        {
            if (k)
                k--;
            else
                cout << arr[i];
        }
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
