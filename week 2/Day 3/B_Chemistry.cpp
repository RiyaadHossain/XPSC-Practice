#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    char arr[n];
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i], cnt[arr[i] - 'a']++;

    bool ans = 0;
    int oddCnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2)
            oddCnt++;
    }

    if ((n % 2 == 0 && oddCnt == 0) || (n % 2 && oddCnt == 1))
        ans = 1;

    if (k >= oddCnt - 1)
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