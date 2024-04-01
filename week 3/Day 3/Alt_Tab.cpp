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

stack<string> st;
void solve()
{
    string str;
    cin >> str;
    st.push(str);
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

    map<string, bool> mpp;
    int sz;
    while (!st.empty())
    {
        if (!mpp.count(st.top()))
        {
            mpp[st.top()] = 1;

            sz = st.top().size();
            cout << st.top()[sz - 2] << st.top()[sz - 1];
        }
        st.pop();
    }

    return 0;
}
