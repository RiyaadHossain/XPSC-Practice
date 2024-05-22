#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    bool changedPrev = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1 && !changedPrev)
            ans++, changedPrev = 1;
        else
            changedPrev = 0;
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