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

    if (n <= 1)
    {
        cout << 2;
        return;
    }

    auto ok = [&](int mid)
    {
        return (mid * (mid - 1)) / 2;
    };

    int ans = 2;
    int left = 0, right = 2e9, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;

        if (ok(mid) <= n)
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    ans += n - ok(ans);

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