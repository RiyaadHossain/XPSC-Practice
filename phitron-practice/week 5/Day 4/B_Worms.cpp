#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

int32_t main()
{
    int n;
    cin >> n;

    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];

    int pre[sum + 1];
    int i = 1, j = 0, tmp = 0;
    while (i <= sum)
    {
        tmp += arr[j];
        while (i <= tmp)
            pre[i++] = j + 1;
        j++;
    }

    int k;
    cin >> k;

    int m;
    while (k--)
    {
        cin >> m;
        cout << pre[m] << endl;
    }

    return 0;
}