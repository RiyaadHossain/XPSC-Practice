#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    char c;
    cin >> n;
    cin >> c;

    char lights[n];
    int minG = 1e6;
    for (int i = 0; i < n; i++)
    {
        cin >> lights[i];
        if (lights[i] == 'g')
            minG = min(minG, i);
    }

    int timeOfG[n];
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            if (lights[i] == 'g')
                timeOfG[i] = 0;
            else
                timeOfG[i] = -1;
            continue;
        }

        if (lights[i] == 'g')
            timeOfG[i] = 0;
        else if (timeOfG[i + 1] != -1)
            timeOfG[i] = timeOfG[i + 1] + 1;
        else
            timeOfG[i] = -1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (lights[i] == c)
        {
            if (i < minG)
                ans = max(ans, minG - i);
            else
            {
                if (timeOfG[i] == -1)
                    ans = max(ans, (n - i) + minG);
                else
                    ans = max(ans, timeOfG[i]);
            }
        }
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