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

    int cnt = 0;
    for (int i = 0; i < 30; i++)
        cnt += ((n & (1 << i)) != 0);

    vector<int> ans;
    while (cnt > 1)
    {
        ans.push_back(n);
        for (int i = 0; i < 30; i++)
        {
            if (n & (1 << i))
            {
                n -= (1 << i), cnt--;
                break;
            }
        }
    }

    while (n >= 1)
    {
        ans.push_back(n);
        n /= 2;
    }

    cout << sz(ans) << endl;
    for (int it : ans)
        cout << it << " ";
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