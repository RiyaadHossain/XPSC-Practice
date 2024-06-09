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
    int n, x;
    cin >> n;

    map<int, vi> mpp;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mpp[x].push_back(i + 1);
    }

    vector<int> dis1, dis2;
    for (auto [x, y] : mpp)
    {
        if (!sz(dis1))
            dis1 = y;
        else
            for (int i : y)
                dis2.push_back(i);
    }

    if (!sz(dis2))
    {
        println("NO");
        return;
    }

    println("YES");
    for (int i = 0; i < sz(dis1) - 1; i++)
        cout << dis1[i] << " " << dis2[0] << endl;

    for (int i : dis2)
        cout << dis1[sz(dis1) - 1] << " " << i << endl;
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
        // cout << '\n';
    }

    return 0;
}