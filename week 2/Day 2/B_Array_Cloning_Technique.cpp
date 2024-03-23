#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int arr[n];

    map<int, int> mpp;
    int totalSameNum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mpp[arr[i]]++;

        if (mpp[arr[i]] > totalSameNum)
            totalSameNum = mpp[arr[i]];
    }

    int operation = 0;

    while (totalSameNum < n)
    {
        // 1. Copy
        operation++;

        // 2. Swap
        int numNeed = n - totalSameNum;
        operation += min(totalSameNum, numNeed);

        totalSameNum *= 2;
    }

    cout << operation;
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