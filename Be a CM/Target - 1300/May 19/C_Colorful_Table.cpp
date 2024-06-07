#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, k;
    cin >> n >> k;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    set<int> st;
    vector<int> pos[k + 1];
    for (int i = 0; i < n; i++)
    {
        pos[arr[i]].push_back(i);
        st.insert(i);
    }

    vector<int> ans(k + 1);
    for (int i = 1; i <= k; i++)
    {
        if (!pos[i].size())
            continue;

        ans[i] = 2 * (*st.rbegin() - *st.begin() + 1);
        for (auto e : pos[i])
            st.erase(e);
    }

    for (int i = 1; i <= k; i++)
        cout << ans[i] << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}