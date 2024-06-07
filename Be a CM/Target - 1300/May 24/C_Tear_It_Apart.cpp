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
    string s;
    cin >> s;

    int n = sz(s);

    auto get = [&](char curr)
    {
        int mx = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == curr)
                mx = max(mx, len), len = 0;
            else
                len++;
        }
        mx = max(mx, len);

        int ans = log2(mx) + 1;
        if (mx == 0)
            ans = 0;

        return ans;
    };

    int result = inf;
    for (char i = 'a'; i <= 'z'; i++)
        result = min(result, get(i));

    cout << result;
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