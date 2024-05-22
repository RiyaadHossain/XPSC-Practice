#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

const int mod = 1e9 + 7;

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int find(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = find(n - 1, dp) % mod + (((n - 1) * find(n - 2, dp) % mod) * 2) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    int r, c;
    set<int> st;
    while (k--)
    {
        cin >> r >> c;
        st.insert(r), st.insert(c);
    }

    int rem = n - st.size();
    vector<int> dp(rem + 1, -1);

    int result = find(rem, dp) % mod;
    cout << result;
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
