#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 1)
            cout << 'a';
        if (i % 4 == 2)
            cout << 'a';
        if (i % 4 == 3)
            cout << 'b';
        if (i % 4 == 0)
            cout << 'b';
    }

    return 0;
}