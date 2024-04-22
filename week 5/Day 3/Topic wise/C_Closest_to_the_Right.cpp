#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int lowerBound(vector<int> &arr, int n, int key)
{
    int left = 0, right = n - 1, ans = n, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] >= key)
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans + 1;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    while (k--)
    {
        cin >> x;
        cout << (lowerBound(arr, n, x)) << endl;
    }

    return 0;
}
