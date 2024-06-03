#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

    vector<int> spend(n);
    for (int i = 0; i < n; i++)
        cin >> spend[i];

    vector<int> budget(n);
    for (int i = 0; i < n; i++)
        cin >> budget[i];

    vector<int> diff;
    for (int i = 0; i < n; i++)
        diff.push_back(budget[i] - spend[i]);

    sort(rall(diff));
    int cnt = 0, j = n - 1;
    for (int i = 0; i < n; i++)
    {
        while (j > i && diff[i] + diff[j] < 0)
            j--;
        if (i >= j)
            break;
        j--;
        cnt++;
    }

    cout << cnt;
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