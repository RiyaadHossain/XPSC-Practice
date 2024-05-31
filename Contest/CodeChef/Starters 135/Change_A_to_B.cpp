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
    int a, b, k;
    cin >> a >> b >> k;

    int ans = 0;
    while (1)
    {
        if (b % k == 0 && b / k >= a)
            b /= k, ans++;
        else if (b / k >= a)
        {
            int x = b - (b / k) * k;
            ans += x, b -= x;
        }
        else
        {
            ans += (b - a);
            break;
        }
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