#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

int32_t main()
{
    int x, n, d;
    cin >> x >> n >> d;
    if (x + d >= n)
        cout << ye;
    else
        cout << no;
    return 0;
}