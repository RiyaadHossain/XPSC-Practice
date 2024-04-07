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

void reset(vector<bool> &track)
{
    for (int i = 0; i < 26; i++)
        track[i] = 0;
}

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    map<char, int> mpp1;
    int suffix[n];
    for (int i = n - 1; i >= 0; i--)
    {
        mpp1[str[i]]++;
        suffix[i] = mpp1.size();
    }

    map<char, int> mpp2;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        mpp2[str[i]]++;
        int rem = mpp2.size() + suffix[i + 1];
        ans = max(ans, rem);
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
