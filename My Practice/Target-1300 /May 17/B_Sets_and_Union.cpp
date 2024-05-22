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

    int s, x;
    set<int> mainSet;
    vector<set<int>> allSet(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        set<int> tmp;
        for (int j = 0; j < s; j++)
        {
            cin >> x;
            mainSet.insert(x);
            tmp.insert(x);
        }
        allSet[i] = tmp;
    }

    int ans = 0;
    for (int i = 1; i <= 50; i++)
    {
        if (!mainSet.count(i))
            continue;

        set<int> tmp;
        for (int j = 0; j < n; j++)
        {
            if (!allSet[j].count(i))
            {
                for (int it : allSet[j])
                    tmp.insert(it);
            }
        }
        ans = max(ans, sz(tmp));
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