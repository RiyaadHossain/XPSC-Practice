#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

int lastOccurance(int *arr, int n, int key)
{
    int left = 0, right = n - 1;
    int ans = -1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            ans = mid;

        if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return ans;
}

int main()
{
    int n, key;
    cin >> n >> key;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = lastOccurance(arr, n, key);
    cout << "Target value last occured at: " << res << " index";

    return 0;
}