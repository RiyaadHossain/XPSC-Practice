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
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int a, b;
    while (q--)
    {
        cin >> a >> b;
        vector<int> idx1, idx2;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
                idx1.push_back(i);
            if (arr[i] == b)
                idx2.push_back(i);
        }

        if (idx1.size() && idx2.size() && idx1[0] <= idx2[idx2.size() - 1])
            cout << ye;
        else
            cout << no;
        cout << '\n';
    }
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
