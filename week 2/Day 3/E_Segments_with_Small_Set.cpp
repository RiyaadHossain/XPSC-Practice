#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mpp;
    int i = 0, j = 0, uniqueEl = 0;
    long long ans = 0;

    while (j < n)
    {
        mpp[arr[j]]++;
        if (mpp[arr[j]] == 1)
            uniqueEl++;

        while (uniqueEl > k)
        {
            mpp[arr[i]]--;
            if (mpp[arr[i]] == 0)
                uniqueEl--;
            i++;
        }

        ans += (j - i + 1);
        j++;
    }

    cout << ans;
}

int main()
{
    solve();
    return 0;
}