#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

void solve(int *a, int n, int key)
{
    int left = 0, right = n - 1, ans = 0, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if ((mid == 0 || a[mid - 1] < key) && a[mid] >= key)
        {
            ans = mid;
            break;
        }

        if (a[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }

    cout << ans + 1 << endl;
}

int32_t main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            a[i] += a[i - 1];
    }

    int q;
    cin >> q;

    int m;
    while (q--)
    {
        cin >> m;
        solve(a, n, m);
    }

    return 0;
}