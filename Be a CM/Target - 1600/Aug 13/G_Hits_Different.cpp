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

void solve()
{
    int num;
    cin >> num;

    auto getLevel = [&](int n) -> int
    {
        if (n == 1)
            return 1;

        int inc = 2, level = 2;
        int left = 2, right = 3;
        while (1)
        {
            if (left <= n && right >= n)
                return level;
            left += inc++;
            right += inc;
            level++;
        }
    };

    auto getStart = [&](int level)
    {
        return ((level * (level - 1)) / 2) + 1;
    };

    auto getEnd = [&](int level)
    {
        return getStart(level) + level - 1;
    };

    auto getLeft = [&](int n, int level)
    {
        int ahead = n - getStart(level);
        int prevSt = getStart(level - 1);
        if (ahead == 0)
            return prevSt;

        return prevSt + ahead - 1;
    };

    auto getRight = [&](int n, int level)
    {
        if (n - getStart(level) + 1 == level)
            return n - level;
        if(getStart(level) == n)
            return getStart(level - 1);
        return getLeft(n, level) + 1;
    };

    auto getSqrtSum = [&](int n)
    {
        return (n * (n + 1) * (2 * n + 1)) / 6;
    };

    auto getSum = [&](int left, int right)
    {
        return getSqrtSum(right) - getSqrtSum(left - 1);
    };


    int sum = num * num;
    int level = getLevel(num);
    int left = getLeft(num, level);
    int right = getRight(num, level);

    while (level >= 1)
    {
        level--;
        if (left == getStart(level) && right == getEnd(level))
        {
            sum += getSqrtSum(right);
            break;
        }

        sum += getSum(left, right);
        left = getLeft(left, level);
        right = getRight(right, level);
    }

    print(sum);
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