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
    int n;
    cin >> n;

    string str;
    cin >> str;

    string ans;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = str[i] - '0';
        if (curr == 0)
        {
            curr = ((str[i - 2] - '0') * 10) + (str[i - 1] - '0');
            i -= 2;
        }

        ans.push_back('a' + (curr-1));
    }

    reverse(ans.begin(), ans.end());
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
