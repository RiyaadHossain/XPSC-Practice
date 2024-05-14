#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<long long> g(a, a + 2);
    for (int i = 0; i < n; i++)
        g[i % 2] = __gcd(g[i % 2], a[i]);

    vector<bool> good(2, true);
    for (int i = 0; i < n; i++)
    {
        good[i % 2] = good[i % 2] && (a[i] % g[(i % 2) ^ 1] > 0);
    }

    for (int it : g)
        cout << it << " ";
    cout << endl;

    return 0;
}