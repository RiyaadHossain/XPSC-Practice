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
    int q;
    cin >> q;

    int x, m;
    int it = 1;
    set<pii> idx, money;
    map<int, set<int>> mpp;
    while (q--)
    {
        cin >> x;

        if (x == 1)
        {
            cin >> m;
            idx.insert({it, m}), money.insert({m, it}), mpp[m].insert(it), it++;
        }
        else if (x == 2)
        {
            int a = (*idx.begin()).a, b = (*idx.begin()).b;
            cout << a << " ";
            idx.erase({a, b}), money.erase({b, a});
        }
        else
        {
            auto ite = --money.end();
            int a = (*ite).a;
            int b = *mpp[a].begin();
            cout << b << " ";
            mpp[a].erase(b);
            money.erase({a, b}), idx.erase({b, a});
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}