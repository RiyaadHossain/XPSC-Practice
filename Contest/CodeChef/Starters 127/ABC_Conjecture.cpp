#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "Yes"
#define no "No"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    string st1, st2;
    cin >> st1 >> st2;

    int ac = 0, bNeed = 0, ca = 0;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (st1[i] == 'a' && st2[i] == 'c')
            ac++, bNeed = 1;
        else if (st1[i] == 'b')
            bNeed = 0;
        else if (st1[i] == 'c' && st2[i] == 'a')
        {
            if (!ac || bNeed)
                ans = false;
            else
                ac--;
        }
        else if (st1[i] != st2[i])
            ans = false;
    }

    cout << (ans ? ye : no);
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
