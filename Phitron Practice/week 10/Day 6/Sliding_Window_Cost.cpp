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

    pbds<pii> pb;
    for (int i = 0; i < k; i++)
        pb.insert({arr[i], i});

    int sum = 0;
    int mid = k / 2;
    int old_mid = (*pb.find_by_order(mid)).a;
    for (int i = 0; i < k; i++)
        sum += abs(arr[i] - old_mid);

    cout << sum << " ";
    for (int i = 0; i < n - k; i++)
    {
        sum -= abs(arr[i] - old_mid);
        pb.erase({arr[i], i});
        pb.insert({arr[i + k], i + k});
        int new_mid = (*pb.find_by_order(mid)).a;
        sum += abs(new_mid - arr[i + k]);

        if (k % 2 == 0)
            sum += (new_mid - old_mid);
        old_mid = new_mid;
        cout << sum << " ";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}