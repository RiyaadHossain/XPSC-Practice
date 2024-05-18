#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mpp;
    int j = 0, ans = 1;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
        while (mpp[arr[i]] > 1)
            mpp[arr[j]]--, j++;

        ans = max(ans, i + 1 - j);
    }

    cout << ans;

    return 0;
}