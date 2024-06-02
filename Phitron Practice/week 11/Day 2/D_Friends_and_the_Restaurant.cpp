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
    int n;
    cin >> n;

    vector<int> spend(n);
    for (int i = 0; i < n; i++)
        cin >> spend[i];

    vector<int> budget(n);
    for (int i = 0; i < n; i++)
        cin >> budget[i];

    int cnt = 0;
    vector<int> sExtra, sLess;
    for (int i = 0; i < n; i++)
    {
        cnt += (spend[i] == budget[i]);
        if (spend[i] < budget[i])
            sLess.push_back(spend[i] - budget[i]);
        if (spend[i] > budget[i])
            sExtra.push_back(budget[i] - spend[i]);
    }

    int j = 0;
    int ans = cnt / 2;

    if (ans % 2 && sz(sLess))
        ans++, j = 1;

    sort(all(sExtra)), sort(all(sLess));

    int tmp1 = ((sz(sLess) - j) / 2), tmp2 = 0;
    for (int i = 0; i < sz(sExtra); i++)
    {
        while (j < n && sExtra[i] > 0)
            sExtra[i] -= sLess[j++];
        if (sExtra[i] <= 0)
            tmp2++;
    }

    ans += max(tmp1, tmp2);

    ans += ((sz(sLess) - j) / 2);
    cout << ans;
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