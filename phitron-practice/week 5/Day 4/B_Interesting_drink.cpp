#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

void solve(vector<int> &a, int n, int d)
{
    int left = 0, right = n - 1, ans = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (a[mid] <= d)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    if (d < a[0])
        ans = -1;

    cout << ans + 1 << endl;
}

int32_t main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    int k;
    cin >> k;

    int d;
    while (k--)
    {
        cin >> d;
        solve(a, n, d);
    }

    return 0;
}