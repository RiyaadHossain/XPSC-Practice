#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    char c;
    cin >> n >> c;

    string lights;
    cin >> lights;
    lights += lights;

    int ans = 0;

    int chIdx = -1;
    for (int i = 0; i < n * 2; i++)
    {

        if (chIdx == -1 && lights[i] == c)
            chIdx = i;

        if (chIdx != -1 && lights[i] == 'g')
            ans = max(ans, i - chIdx), chIdx = -1;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}