#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n, x;
    cin >> n >> x;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0, sum = 0;
    map<int, int> mpp;
    mpp[0]++;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ans += mpp[sum - x];
        mpp[sum]++;
    }

    cout << ans;

    return 0;
}