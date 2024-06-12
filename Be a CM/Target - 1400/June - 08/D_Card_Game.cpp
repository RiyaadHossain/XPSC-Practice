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
    int n;
    cin >> n;

    string suits = "SCDH";

    char ch;
    cin >> ch;

    int trum = suits.find(ch);

    vector<int> bs[4];
    for (int i = 0; i < 2 * n; i++)
    {
        string card;
        cin >> card;

        bs[suits.find(card[1])].push_back(card[0] - '2');
    }

    vector<string> res, left;
    for (int i = 0; i < 4; i++)
    {
        sort(all(bs[i]));
        if (i == trum)
            continue;

        if (sz(bs[i]) % 2)
        {
            int x = bs[i].back();
            bs[i].pop_back();
            left.push_back(string() + char(x + '2') + suits[i]);
        }

        for (int j = 0; j < sz(bs[i]); j++)
        {
            int x = bs[i][j];
            res.push_back(string() + char(x + '2') + suits[i]);
        }
    }

    if (sz(left) > sz(bs[trum]))
    {
        println("IMPOSSIBLE");
        return;
    }

    while (sz(left))
    {
        res.push_back(left.back());
        left.pop_back();
        int x = bs[trum].back();
        res.push_back(string() + char(x + '2') + suits[trum]);
        bs[trum].pop_back();
    }

    sort(rall(bs[trum]));
    while (sz(bs[trum]))
    {
        int x = bs[trum].back();
        res.push_back(string() + char(x + '2') + suits[trum]);
        bs[trum].pop_back();
    }

    for (int i = 0; i < n * 2; i += 2)
        cout << res[i] << " " << res[i + 1] << endl;
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