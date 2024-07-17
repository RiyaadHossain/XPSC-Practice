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
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

bool check(vvi &cake, vi order, int avg)
{
    int n = sz(cake[0]);
    int left = 0, cnt = 0;
    vpi ans(3);
    forr(i, 0, 2)
    {
        int sum = 0;
        forr(j, left, n - 1)
        {
            sum += cake[order[i]][j];
            if (sum >= avg)
            {
                cnt++;
                int right = cnt == 3 ? n - 1 : j;
                ans[order[i]] = {left, right};
                left = j + 1;
                break;
            }
        }
    }

    if (cnt == 3)
    {
        for (auto x : ans)
            printsp(x.a + 1), printsp(x.b + 1);
        println(" ");
        return 1;
    }

    return 0;
}

void solve()
{
    int n;
    cin >> n;
    vvi cake(3, vi(n));

    forr(i, 0, 2)
    {
        forr(j, 0, n - 1)
                cin >>
            cake[i][j];
    }

    int avg = (accumulate(all(cake[0]), 0ll) + 2) / 3;

    vvi permutations = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
    for (auto order : permutations)
    {
        if (check(cake, order, avg))
            return;
    }

    println(-1);
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
    }

    return 0;
}