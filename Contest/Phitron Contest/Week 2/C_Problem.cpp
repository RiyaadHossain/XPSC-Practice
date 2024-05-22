#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    bool ans = 0;

    if (n == m)
        ans = 1;

    if (n > m)
    {
        while (n > m)
        {
            n--, m += 1;
            if (n == m)
            {
                ans = 1;
                break;
            }
        }
    }
    else
    {
        while (m > n)
        {
            m--, n += 3;
            if (n == m)
            {
                ans = 1;
                break;
            }
        }
    }

    if (n - m == 2 || m - n == 4 || n - m == 0)
        cout << "YES";
    else
        cout << "NO";
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