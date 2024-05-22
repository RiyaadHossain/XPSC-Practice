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

void solve()
{
    string time;
    cin >> time;

    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    string amOrpm = hour <= 11 ? "AM" : "PM";

    hour = hour % 12 == 0 ? 12 : hour % 12;

    string hourS = to_string(hour);
    if (hourS.size() == 1)
        hourS = "0" + hourS;

    cout << hourS << ":" << time[3] << time[4] << " " << amOrpm;
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
