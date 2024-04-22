#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

int firstOccurance(int *arr, int n, int key)
{
    int left = 0, right = n - 1, mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid;
    }

    return right;
}

// Simplier Version
int firstOccurance2(int *arr, int n, int key)
{
    int left = 0, right = n - 1, mid, ans = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            ans = mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
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

    int res = firstOccurance2(arr, n, key);
    cout << "Target value first occured at: " << res << " index";

    return 0;
}