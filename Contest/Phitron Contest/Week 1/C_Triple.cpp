#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[num]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (arr[i] >= 3)
        {
            cout << i << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}