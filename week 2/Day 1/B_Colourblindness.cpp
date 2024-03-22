#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string color1, color2;
    cin >> color1 >> color2;

    for (int i = 0; i < n; i++)
    {
        char c1 = color1[i], c2 = color2[i];
        if (!((c1 == 'R' && c2 == 'R') || (c1 != 'R' && c2 != 'R')))
        {
            cout << "NO";
            return;
        }
    }

    cout << "YES";
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