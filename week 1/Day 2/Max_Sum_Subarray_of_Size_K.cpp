#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = 0;
    long long ans = 0, sum = 0;
    while (i < n && j < n)
    {
        sum += arr[j];

        while (j - i + 1 > k)
            sum -= arr[i++];

        ans = max(ans, sum);
        j++;
    }

    cout << ans;

    return 0;
}