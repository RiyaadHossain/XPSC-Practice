#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    int minVal = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        minVal = min(minVal, arr[i]);
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += (arr[i] - minVal);

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();
    return 0;
}