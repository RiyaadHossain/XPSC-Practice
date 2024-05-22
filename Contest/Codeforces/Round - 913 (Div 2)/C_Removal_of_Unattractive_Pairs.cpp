#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> track(26);
    for (int i = 0; i < n; i++)
    {
        track[str[i] - 'a']++;
    }

    int mx = 0;
    for (int i = 0; i < 26; i++)
    {
        mx = max(mx, track[i]);
    }

    int rem = n - mx;

    if (rem == mx)
        cout << 0;
    else if (mx > rem)
        cout << (mx - rem);
    else
    {
        if ((rem - mx) % 2)
            cout << 1;
        else
            cout << 0;
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
        cout << '\n';
    }

    return 0;
}
