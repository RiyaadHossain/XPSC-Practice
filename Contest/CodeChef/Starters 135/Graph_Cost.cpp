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
    int n;
    cin >> n;

    set<pii> st;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i], st.insert({arr[i], i});

    int ans = 0, i = 0;
    while (i < n)
    {
        st.erase({arr[i], i});
        if (st.empty())
            break;

        int next = (*(--st.end())).a;
        if (arr[i] > next)
        {
            ans += arr[i++];
            continue;
        }

        int it = (*st.begin()).b;
        ans += ((it - i) * max(arr[i], arr[it]));
        while (it != i)
            st.erase({arr[i], i}), i++;
    }

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