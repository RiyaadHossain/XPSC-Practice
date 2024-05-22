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

    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    vector<int> prefix(n);
    prefix[0] = arr[0].first;
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i].first;

    stack<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        st.push(arr[i].second);
        if (i == n - 1 || prefix[i] < arr[i + 1].first)
        {
            while (!st.empty())
            {
                ans[st.top()] = i;
                st.pop();
            }
        }
    }

    for (int it : ans)
        cout << it << " ";
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
