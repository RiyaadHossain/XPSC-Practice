#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int n;
vector<int> arr;
int firstOccur(int key)
{
    int left = 0, right = n - 1, ans = 0, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] >= key)
            ans = mid, right = mid - 1;
        else
            left = mid + 1;
    }

    return ans + 1;
}

int lastOccur(int key)
{
    int left = 0, right = n - 1, ans = n - 1, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (arr[mid] <= key)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    return ans + 1;
}

void solve()
{
    int k;
    cin >> k;

    int a, b;
    while (k--)
    {
        cin >> a >> b;
        a = firstOccur(a);
        b = lastOccur(b);

        cout << b + 1 - a << " ";
    }
}

int32_t main()
{
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    solve();

    return 0;
}