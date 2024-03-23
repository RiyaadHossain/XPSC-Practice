#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int firstIdx = -1;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            firstIdx = i;
            break;
        }
    }

    if (firstIdx == -1)
    {
        cout << "YES";
        return;
    }

    int i = 0, j = n - 1;
    bool isFail = 0;
    while (i < j)
    {
        while (arr[i] == arr[firstIdx])
            i++;
        while (arr[j] == arr[firstIdx])
            j--;

        if (arr[i] != arr[j])
        {
            isFail = 1;
            break;
        }
        i++, j--;
    }

    if (!isFail)
    {
        cout << "YES";
        return;
    }

    firstIdx = n - firstIdx - 1, i = 0, j = n - 1;
    while (i < j)
    {
        while (arr[i] == arr[firstIdx])
            i++;
        while (arr[j] == arr[firstIdx])
            j--;

        if (arr[i] != arr[j])
        {
            cout << "NO";
            return;
        }
        i++, j--;
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