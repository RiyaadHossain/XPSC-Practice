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
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)
#define forEach(x, ds) for (auto &x : ds)

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)
#define dsFind(ds, x) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

vector<pi> range(3);

int n, target;
vvi orders = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
bool check(vi order, vvi cakes)
{
    int idx = 0, sum = 0, left = 0;
    forr(i, 0, n - 1)
    {
        sum += cakes[order[idx]][i];
        if (sum >= target)
        {
            int right = idx < 2 ? i + 1 : n;
            range[order[idx]] = {left + 1, right};
            sum = 0, idx++;
            left = i + 1;
        }

        if (idx == 3)
            break;
    }

    if (idx < 3)
        return 0;

    forr(i, 0, 2)
    {
        printsp(range[i].a);
        printsp(range[i].b);
    }

    return 1;
}

void solve()
{
    n;
    cin >> n;

    vvi cakes(3, vi(n));
    forr(i, 0, 2)
    {
        forr(j, 0, n - 1)
        {
            cin >> cakes[i][j];
        }
    }

    target = (accumulate(all(cakes[0]), 0ll) + 2) / 3;

    forEach(order, orders)
    {
        if (check(order, cakes))
            return;
    }

    print(-1);
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