#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

bool isPilan(int h, int m)
{
    string hour = to_string(h);
    if (hour.size() == 1)
        hour = "0" + to_string(h);

    string min = to_string(m);
    if (min.size() == 1)
        min = "0" + to_string(m);

    return (hour[0] == min[1] && hour[1] == min[0]);
}

void solve()
{
    string time;
    cin >> time;

    int x;
    cin >> x;

    int ans = 0;
    int hour = (time[0] - '0') * 10 + time[1] - '0';
    int min = (time[3] - '0') * 10 + time[4] - '0';
    int h = hour, m = min;
    while (1)
    {
        if (isPilan(hour, min))
            ans++;
        hour += x / 60;
        min += x % 60;
        hour += min / 60, min = min % 60;
        hour %= 24;

        if (h == hour && m == min)
            break;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
