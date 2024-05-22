#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b;
    cin >> a >> b;

    long long ans = 0;
    while (a <= b)
    {
        a *= 2;
        ans++;
    }

    cout << ans;

    return 0;
}