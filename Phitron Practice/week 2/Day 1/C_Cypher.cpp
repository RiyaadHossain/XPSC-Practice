#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            char ch;
            cin >> ch;

            if (ch == 'U')
                curr--;
            else
                curr++;

            if (curr == 10)
                curr = 0;
            if (curr == -1)
                curr = 9;
        }

        arr[i] = curr;
    }

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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