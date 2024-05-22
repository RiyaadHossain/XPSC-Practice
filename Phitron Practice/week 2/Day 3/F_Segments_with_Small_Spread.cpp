#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll n, k;
    cin >> n >> k;

    ll arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = 0;
    ll ans = 0;

    multiset<ll> ms;
    while (j < n)
    {
        ms.insert(arr[j]);

        while (*ms.rbegin() - *ms.begin() > k)
            ms.erase(ms.find(arr[i++]));

        ans += (j - i + 1);
        j++;
    }

    cout << ans;
}

int main()
{
    solve();
    return 0;
}