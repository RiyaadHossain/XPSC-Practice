#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string stamps;
    cin >> stamps;

    bool ans = 1;

    for (int i = 0; i < n; i++)
    {
        if (stamps[i] != 'W')
        {
            int r = 0, b = 0;
            while (i < n && stamps[i] != 'W')
            {
                if (stamps[i] == 'B')
                    b++;
                else
                    r++;
                i++;
            }

            if (r == 0 || b == 0)
            {
                ans = 0;
                break;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}