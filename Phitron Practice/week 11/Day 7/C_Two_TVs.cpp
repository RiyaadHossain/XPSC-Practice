#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve1()
{
    int n;
    cin >> n;

    vector<pii> prog(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prog[i].a;
        cin >> prog[i].b;
    }

    sort(all(prog));

    pbds<int> pb;
    for (int i = 0; i < n; i++)
    {
        pb.insert(prog[i].b);
        if (sz(pb) - pb.order_of_key(prog[i].a) > 2)
        {
            no;
            return;
        }
    }

    ye;
}

void solve2()
{
    int n;
    cin >> n;

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;

        mpp[l]++, mpp[r + 1]--;
    }

    int sum = 0;
    for (auto [x, y] : mpp)
    {
        sum += y;
        if (sum > 2)
        {
            no;
            return;
        }
    }

    ye;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve2();

    return 0;
}