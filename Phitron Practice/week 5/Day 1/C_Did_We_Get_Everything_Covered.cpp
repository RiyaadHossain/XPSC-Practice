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
    int n, k, m;
    cin >> n >> k >> m;

    string str;
    cin >> str;

    set<int> st;
    string ans;
    for (int i = 0; i < m; i++)
    {
        st.insert(str[i] - 'a');
        if (st.size() == k)
            ans += str[i], st.clear();
    }

    if (ans.size() >= n)
    {
        cout << ye;
        return;
    }

    for (int i = 0; i < k; i++)
    {
        if (st.count(i) == 0)
        {
            ans += char('a' + i);
            break;
        }
    }

    while (ans.size() < n)
        ans += 'a';

    cout << no << endl;
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
