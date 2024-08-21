#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
#define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forEach(x, ds) for (auto &x : ds)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)

// Shortcut Functions
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcountll(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Constant Varialbes
const int inf = 1e9;
const int llinf = 1e18;
const int mod = 1e9 + 7;
const int N = 1e7;

int  x, y, x1, i, j, p[N + 1], diff;
void generate()
{

    for (i = 1; i <= N; i++)
        p[i] = i;

    for (i = 2; i <= N; i++)
        if (p[i] == i)
            for (j = i * i; j <= N; j += i)
                if (p[j] == j)
                    p[j] = i;
}

void solve()
{
    // Tutorial: https://www.youtube.com/watch?v=2uHiZHjabZU
    cin >> x >> y;

    x1 = N;

    diff = y - x;
    if (diff == 1)
    {
        print(-1);
        return;
    }

    while (diff > 1)
    {
        j = p[diff];

        // Calculate the minimum x with current prime factorization
        if ((x % j) == 0)
            x1 = x;
        else
            x1 = min(x1, (x / j + 1) * j);

        // Try other prime factorization of diff to get lower value
        while ((diff % j) == 0)
            diff /= j;
    }

    print(x1 - x);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    generate();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}