#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    long long sum = 0;
    int oddCnt = 0, minOdd = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            minOdd = min(minOdd, arr[i]);
            oddCnt++;
        }

        sum += arr[i];
    }

    if (oddCnt % 2)
        sum -= minOdd;

    cout << sum;

    return 0;
}