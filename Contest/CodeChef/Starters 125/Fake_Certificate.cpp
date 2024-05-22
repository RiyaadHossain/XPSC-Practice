#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void solve()
{
    int n;
    cin >> n;

    char arr[n];
    int ones = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == '1')
            ones++;
    }

    int mxZeros = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (i < n && arr[i] == '0')
            cnt++, i++;
        mxZeros = max(mxZeros, cnt);
    }

    cout << ones + mxZeros;
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
