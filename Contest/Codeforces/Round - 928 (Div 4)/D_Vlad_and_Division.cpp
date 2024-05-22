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

int MASK = INT_MAX;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    multiset<int> ml;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ml.find(MASK ^ arr[i]) != ml.end())
            ans++, ml.erase(ml.find(MASK ^ arr[i]));
        else
            ml.insert(arr[i]);
    }

    cout << (ans + ml.size());
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
