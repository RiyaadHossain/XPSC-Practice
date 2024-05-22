#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    auto ok = [&](int key)
    {
        int op = 0;
        for (int i = n / 2; i < n; i++)
        {
            if(key > arr[i])
                op += (key - arr[i]);
        }

        return op <= k;
    };

    int ans = 0;
    int left = 0, right = 1e12, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}