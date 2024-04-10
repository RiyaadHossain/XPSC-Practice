#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n, b;
    cin >> n >> b;

    int arr[n];
    vector<int> superMask;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if ((arr[i] & b) == b)
            superMask.push_back(arr[i]);
    }

    if (superMask.empty())
    {
        cout << no;
        return;
    }

    int AND = superMask[0];
    for (int i = 1; i < superMask.size(); i++)
        AND &= superMask[i];

    cout << (AND == b ? ye : no);
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
