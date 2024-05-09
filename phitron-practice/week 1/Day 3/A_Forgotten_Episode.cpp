#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            ans = i + 1;
            break;
        }
    }

    cout << ans;

    return 0;
}