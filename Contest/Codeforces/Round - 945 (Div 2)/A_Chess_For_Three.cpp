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
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;

    int sum = p1 + p2 + p3;
    if (sum % 2)
    {
        cout << -1;
        return;
    }

    int ans = 0;
    int x = min(p1, p3 - p2);
    ans += x;
    p1 -= x;
    p3 -= x;

    if (p1 != 0)
    {
        ans += p1;
        p2 -= p1 / 2;
        p3 -= p1 / 2;
    }

    ans += min(p2, p3);
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