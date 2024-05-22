#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll profit = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll currProfit = profit + arr[i] * 2;
        ans = max(ans, currProfit);
        profit += arr[i];
    }

    cout << ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}