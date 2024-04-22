#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

bool binarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1, ans = 0, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
        {
            ans = 1;
            break;
        }

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int x;
    while (k--)
    {
        cin >> x;
        cout << (binarySearch(arr, n, x) ? ye : no) << endl;
    }

    return 0;
}