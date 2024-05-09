#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    bool found = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
        {
            cout << i;
            found = 1;
            break;
        }
    }

    if (!found)
        cout << -1;

    return 0;
}