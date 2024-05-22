#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

void solve()
{
    int n, q;
    cin >> n >> q;

    int heights[n], widths[n];
    for (int i = 0; i < n; i++)
        cin >> heights[i] >> widths[i];

    while (q--)
    {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (heights[i] > h1 && heights[i] < h2 && widths[i] > w1 && widths[i] < w2)
                ans += (heights[i] * widths[i]);
        }

        cout << ans;
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
