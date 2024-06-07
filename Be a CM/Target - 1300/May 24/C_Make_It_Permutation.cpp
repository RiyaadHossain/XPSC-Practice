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
    int n, c, d;
    cin >> n >> c >> d;

    set<int> st;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i], st.insert(arr[i]);

    int ans = (n - sz(st)) * c;
    int add = 0, more = llinf, it = 1, sz = sz(st);

    for (int curr : st)
    {
        more = min(more, ((curr - it) * d) + ((sz - it) * c));
        it++;
    }

    ans += more;
    if (st.count(1) == 0)
        ans = min(ans, d + (n * c));

    cout << ans;
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