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

bool isPrime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }

    return 1;
}

int spf(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return i;
    }
    return num;
}

void solve()
{
    int l, r;
    cin >> l >> r;

    if (r < 4 || (l == r && isPrime(l)))
        cout << -1;
    else if (l == r)
        cout << r - spf(r) << " " << spf(r);
    else
        cout << 2 << " " << (r = r - (r % 2)) - 2;
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
