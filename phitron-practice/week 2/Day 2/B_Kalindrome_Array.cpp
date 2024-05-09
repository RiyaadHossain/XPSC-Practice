#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
bool check(int idx)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (arr[i] == arr[idx])
            i++;
        while (arr[j] == arr[idx])
            j--;

        if (arr[i] != arr[j])
            return 0;
        i++, j--;
    }

    return 1;
}

void solve()
{
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int idx = -1;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            idx = i;
            break;
        }
    }

    bool ans = 0;
    if (idx == -1)
        ans = 1;

    if (check(idx))
        ans = 1;

    idx = n - idx - 1;
    if (check(idx))
        ans = 1;

    cout << (ans ? "YES" : "NO");
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