#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto findGCD = [&](int idx)
    {
        int g = 0;
        for (int i = idx; i < n; i += 2)
        {
            g = __gcd(g, arr[i]);
        }
        return g;
    };

    auto isNotPair = [&](int idx, int g)
    {
        for (int i = idx; i < n; i += 2)
        {
            if (arr[i] % g == 0)
                return false;
        }
        return true;
    };

    int poss1 = findGCD(0);
    if (isNotPair(1, poss1))
    {
        cout << poss1;
        return;
    }

    int poss2 = findGCD(1);
    if (isNotPair(0, poss2))
    {
        cout << poss2;
        return;
    }

    cout << 0;
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
