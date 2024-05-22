#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int i = 3;
    int sum = 0;
    while (i--)
    {
        sum += n % 10;
        n /= 10;
    }

    int sum2 = 0;
    i = 3;
    while (i--)
    {
        sum2 += n % 10;
        n /= 10;
    }

    cout << (sum == sum2 ? "YES" : "NO") << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}