#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> st;
    for (int i = 1; i <= n; i++)
        st.insert(i);

    vector<int> rem;
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i]) != st.end())
            st.erase(arr[i]);
        else
            rem.push_back(arr[i]);
    }

    int ans = rem.size();

    sort(rem.begin(), rem.end());

    int val;
    for (int i = 0; i < rem.size(); i++)
    {
        val = *st.begin();
        if (val <= (rem[i] - 1) / 2)
            st.erase(val);
        else
        {
            cout << -1;
            return;
        }
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
