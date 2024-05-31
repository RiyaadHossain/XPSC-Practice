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

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        vector<int> diff;
        int it = k, j = i - 1;
        while (j >= 0 && it)
        {
            if (arr[j] <= arr[i])
                break;
            diff.push_back(arr[j] - arr[i]);
            j--, it--;
        }

        it = k, j = i + 1;
        while (j < n && it)
        {
            if (arr[j] <= arr[i])
                break;
            diff.push_back(arr[j] - arr[i]);
            j++, it--;
        }

        for (int a = 0; a < sz(diff); a++)
        {
            int sum = 0;
            for (int b = a; b < sz(diff); b++)
            {
                int len = b + 1 - a;
                if (len > k)
                    break;
                sum += diff[b];
                mpp[len] = max(mpp[len], sum);
            }
        }
    }

    int sum = accumulate(all(arr), 0);
    int mxSub = 0;
    for (auto [x, y] : mpp)
        cout << x << " " << y << endl; // mxSub = max(mxSub, y + mpp[k - x]);

    cout << sum - mxSub;
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