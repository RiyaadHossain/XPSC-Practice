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

    ll ans = 0;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        ll exp = (arr[i] * 3);
        if (arr[i] > 1 && exp % (arr[i] - 1) == 0)
            ans += mpp[exp / (arr[i] - 1)];
        mpp[arr[i]]++;
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