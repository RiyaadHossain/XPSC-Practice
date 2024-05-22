#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    int big = -1;
    for (int i = 0; i < n; i++)
    {
        if (big < arr[i])
            big = arr[i];
        if (arr[i] < big)
            ans += big - arr[i];
    }

    cout << ans;

    return 0;
}