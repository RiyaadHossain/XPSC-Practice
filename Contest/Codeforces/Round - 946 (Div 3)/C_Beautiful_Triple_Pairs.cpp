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

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    int ans = 0;
    map<pair<int, pii>, int> gen;
    map<pii, int> mpp1, mpp2, mpp3;
    for (int i = 0; i < n - 2; i++)
    {
        int cnt = gen[{a[i], {a[i + 1], a[i + 2]}}];

        ans += mpp1[{a[i], a[i + 1]}] - cnt;
        ans += mpp2[{a[i], a[i + 2]}] - cnt;
        ans += mpp3[{a[i + 1], a[i + 2]}] - cnt;

        mpp1[{a[i], a[i + 1]}]++;
        mpp2[{a[i], a[i + 2]}]++;
        mpp3[{a[i + 1], a[i + 2]}]++;
        gen[{a[i], {a[i + 1], a[i + 2]}}]++;
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