#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + a[i];

    map<int, int> seen;
    seen[0]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (prefix[i] < 0)
            prefix[i] = (prefix[i] % n) + n;
        ans += (seen[prefix[i] % n]);
        seen[prefix[i] % n]++;
    }

    cout << ans;

    return 0;
}