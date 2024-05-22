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
    int n, x;
    cin >> n >> x;

    auto get = [&](int num)
    {
        return (num + 2) / 2;
    };

    int val = n - x;
    set<int> possibleKs;
    for (int i = 1; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            if (i % 2 == 0)
                possibleKs.insert(get(i));
            if ((val / i) % 2 == 0)
                possibleKs.insert(get(val / i));
        }
    }

    val = n + x - 2;
    for (int i = 1; i * i <= val; i++)
    {
        if (val % i == 0)
        {
            if (i % 2 == 0)
                possibleKs.insert(get(i));
            if ((val / i) % 2 == 0)
                possibleKs.insert(get(val / i));
        }
    }

    int cnt = 0;
    for (auto &it : possibleKs)
        if (it >= x)
            cnt++;

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
