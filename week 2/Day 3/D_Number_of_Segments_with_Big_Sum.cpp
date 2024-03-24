#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    ll i = 0, j = 0;
    ll sum = 0, ans = 0;
    while (j < n)
    {
        sum += arr[j];

        while (sum >= s)
        {
            ans += (n - j);
            sum -= arr[i++];
        }

        j++;
    }

    cout << ans;
}

int main()
{
    solve();
    return 0;
}