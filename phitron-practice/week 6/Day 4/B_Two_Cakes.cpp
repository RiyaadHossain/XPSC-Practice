#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n, a, b;
    cin >> n >> a >> b;

    auto ok = [&](int pieces)
    {
        if ((a / pieces) == 0 || (b / pieces) == 0)
            return false;

        int plates = (a / pieces) + (b / pieces);
        return plates >= n;
    };

    int ans = 0;
    int left = 1, right = max(a, b), mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    cout << ans;

    return 0;
}