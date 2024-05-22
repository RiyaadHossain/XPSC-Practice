#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll llinf = 1e18;

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second
#define ins insert
#define lb lower_bound // First element NOT LESS than val
#define ub upper_bound // First element GREATER than val

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i < (b); ++i)
#define rforr(i, a, b) for (int i = (a); i > (b); --i)
#define forEach(x, vec) for (auto &x : vec)

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += mpp[arr[i]];
        if (arr[i] == 1)
            ans += mpp[2];
        if (arr[i] == 2)
            ans += mpp[1];
        mpp[arr[i]]++;
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
