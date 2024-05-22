#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int a, b, k1, k2, q1, q2;
    cin >> a >> b >> k1 >> k2 >> q1 >> q2;

    auto getPos = [&](int x, int y)
    {
        set<pii> pos;
        pos.insert({x - a, y - b});
        pos.insert({x - a, y + b});
        pos.insert({x - b, y - a});
        pos.insert({x - b, y + a});
        pos.insert({x + a, y - b});
        pos.insert({x + a, y + b});
        pos.insert({x + b, y - a});
        pos.insert({x + b, y + a});
        return pos;
    };

    set<pii> kingPos = getPos(k1, k2);
    set<pii> queenPos = getPos(q1, q2);

    int cnt = 0;
    for (auto k : kingPos)
    {
        for (auto q : queenPos)
            cnt += (k == q);
    }

    cout << cnt;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
