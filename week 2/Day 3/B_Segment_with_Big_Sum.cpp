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

    int i = 0, j = 0, ans = 1e5;
    ll sum = 0;
    while (j < n)
    {
        sum += arr[j];

        while (sum > s)
        {
            if (sum - arr[i] < s)
                break;
            sum -= arr[i++];
        }

        if (sum >= s)
            ans = min(ans, j - i + 1);
        j++;
    }

    cout << (ans != 1e5 ? ans : -1);
}

int main()
{
    solve();
    return 0;
}