#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"

int main()
{
    int n;
    cin >> n;

    int ans = 0;
    while (n)
    {
        if (n & 1)
            ans++;
        n >>= 1;
    }

    cout << ans;

    return 0;
}