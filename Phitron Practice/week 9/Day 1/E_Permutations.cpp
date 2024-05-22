#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{

    int n;
    cin >> n;

    if (2 <= n && n <= 3)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    vector<int> ans(n + 1);
    int it1 = n / 2, it2 = n;
    if (n % 2 == 0)
        swap(it1, it2);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2)
            ans[i] = it2--;
        else
            ans[i] = it1--;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";

    return 0;
}