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
    int n;
    cin >> n;

    string s, r;
    cin >> s;

    r = s;
    reverse(all(r));
    map<char, vi> cnt_s, cnt_r;
    for (int i = 0; i < n; i++)
    {
        cnt_s[s[i]].push_back(i);
        cnt_r[r[i]].push_back(i);
    }

    vector<int> permutation(n);
    for (char i = 'a'; i <= 'z'; i++)
    {
        for (int j = 0; j < cnt_r[i].size(); j++)
            permutation[cnt_r[i][j]] = cnt_s[i][j];
    }

    int inv = 0;
    pbds<int> p;
    for (int i = n - 1; i >= 0; i--)
    {
        p.insert(permutation[i]);
        inv += (p.order_of_key(permutation[i]));
    }

    cout << inv;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}