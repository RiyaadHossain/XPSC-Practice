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
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n), b(k);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;

    auto update = [&](int idx)
    {
        for (int i = 0; i < b[idx]; i++)
            a[i]++;
    };

    auto find = [&](vector<int> &a)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
            cnt += (a[i] == i + 1);
        
        return cnt;
    };

    int ans = 0, currSc;
    for (int i = 0; i < min(2 * n, d); i++)
    {
        currSc = find(a);
        ans = max(ans, currSc + (d - (i + 1)) / 2);
        update(i % k);
    }

    cout << ans;
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
