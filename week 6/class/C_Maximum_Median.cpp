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

    int medi = n / 2;
    vector<int> a(medi + 1);
    for (int i = medi; i < n; i++)
        a[i - medi] = arr[i];

    int ans = 0;
    int left = a[0], right = a[medi - 1] + k, mid, operations;
    while (left <= right)
    {
        mid = (left + right) / 2;
        operations = 0;
        for (int i = 0; i <= medi; i++)
        {
            if (mid > a[i])
                operations += (mid - a[i]);
        }

        if (operations <= k)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}