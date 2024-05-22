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
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(k + 1), b(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    while (q--)
    {
        int d;
        cin >> d;

        int it = upper_bound(all(a), d) - a.begin();
        int ans = b[it - 1];
        int dis = a[it] - a[it - 1];
        int time = b[it] - b[it - 1];
        int ex = d - a[it - 1];

        ans += ((ex * time) / dis);
        cout << ans << " ";
    }
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