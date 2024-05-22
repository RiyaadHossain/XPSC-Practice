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

    int sum = 0, ans = 0;
    int i = 0, j = 0;
    while (j < n)
    {
        sum += arr[j];
        while (sum > x)
            sum -= arr[i++];

        ans += (sum == x);
        j++;
    }

    cout << ans;

    return 0;
}