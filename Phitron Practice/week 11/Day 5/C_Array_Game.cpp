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
#define print(...) cout << (__VA_ARGS__)
#define println(...) cout << (__VA_ARGS__) << '\n'

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
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = *min_element(all(arr));
    if (k >= 3)
        ans = 0;

    vi diff;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = abs(arr[i] - arr[j]);
            ans = min(ans, x);
            diff.push_back(x);
        }
    }

    if (k > 1)
    {
        sort(all(arr)), sort(all(diff));
        int i = 0, j = 0;

        while (i < n && j < sz(diff))
        {
            ans = min(ans, abs(arr[i] - diff[j]));
            if (arr[i] < diff[j])
                i++;
            else if (arr[i] > diff[j])
                j++;
            else
                break;
        }
    }

    print(ans);
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