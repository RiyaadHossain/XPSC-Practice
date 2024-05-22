#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n], sum = 0;
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];

    if (sum < n)
    {
        cout << "NO";
        return;
    }

    if (k == 0 && sum % n)
    {
        cout << "NO";
        return;
    }

    cout << "YES";
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