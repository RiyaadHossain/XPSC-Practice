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
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    string river;
    cin >> river;

    bool poss = 0;
    int curr = -1;
    while (curr < n)
    {
        if(curr >= 0 && river[curr] == 'C') break;
        if(curr >= 0 && river[curr] == 'W') {
            if(k)
                k--, curr++;
            else break;
            continue;
        }

        int water = -1, log = -1;
        forr(i, curr+1, curr+m)
        {
            if(i == n) {    poss =1;break;}
            if(river[i] == 'L')
                log = i;
            if(river[i] == 'W')
                water= i;
        }

        if(log>=0) curr = log;
        else if(water>=0) curr = water;
        else break;
    }

    poss |= curr == n;
    poss ? ye : no;
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