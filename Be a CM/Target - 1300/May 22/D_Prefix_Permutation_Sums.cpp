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

    vector<int> a(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];

    vector<int> diff;
    diff.push_back(a[0]);
    for (int i = 1; i < n - 1; i++)
        diff.push_back(a[i] - a[i - 1]);
    

    sort(all(diff));
    vector<int> dup;
    if (diff[0] > n)
        dup.push_back(diff[0]);
    for (int i = 1; i < n - 1; i++)
    {
        if (diff[i] == diff[i - 1] || diff[i] > n)
            dup.push_back(diff[i]);
    }

    set<int> st(all(diff));
    vector<int> missing;
    for (int i = 1; i <= n; i++)
    {
        if (st.count(i) == 0)
            missing.push_back(i);
    }

    if (sz(missing) == 1 && sz(dup) == 0)
    {
        ye;
        return;
    }

    if (sz(missing) > 2 || sz(dup) > 1)
    {
        no;
        return;
    }

    if (missing[0] + missing[1] == dup[0])
        ye;
    else
        no;
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