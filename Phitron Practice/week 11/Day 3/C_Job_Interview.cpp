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
    int n, m;
    cin >> n >> m;

    vector<int> prog(n + m + 1), test(n + m + 1);
    for (int i = 0; i < n + m + 1; i++)
        cin >> prog[i];
    for (int i = 0; i < n + m + 1; i++)
        cin >> test[i];

    vector<pair<int, char>> track(n + m + 1);

    int p = 0, t = 0, sum = 0, idx = -1;
    for (int i = 0; i < n + m + 1; i++)
    {
        if (p == n + 1)
        {
            sum += test[i], track[i] = {test[i], 't'};
            idx = idx != -1 ? idx : i - 1;
            continue;
        }

        if (t == m + 1)
        {
            sum += prog[i], track[i] = {prog[i], 'p'};
            idx = idx != -1 ? idx : i - 1;
            continue;
        }

        if (prog[i] > test[i])
            sum += prog[i], track[i] = {prog[i], 'p'}, p++;
        if (prog[i] < test[i])
            sum += test[i], track[i] = {test[i], 't'}, t++;
    }

    idx = idx != -1 ? idx : n + m;

    char ex = p == n + 1 ? 'p' : 't';
    pii last = {prog[idx], test[idx]};
    if (t == m + 1)
        last = {test[idx], prog[idx]};

    for (auto [x, y] : track)
    {
        int tmp = sum;
        tmp -= x;
        if (y != ex)
            tmp -= last.a, tmp += last.b;
        cout << tmp << " ";
    }
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