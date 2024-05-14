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

const int N = 1e6 + 1;
vector<bool> sieve(N, 1);

void generate()
{
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
            continue;

        for (int j = i + i; j < N; j += i)
            sieve[j] = 0;
    }
}

void solve()
{
    int d;
    cin >> d;

    int div1, div2;
    for (int i = 1 + d; i < N; i++)
    {
        if (sieve[i])
        {
            div1 = i;
            break;
        }
    }

    for (int i = div1 + d; i < N; i++)
    {
        if (sieve[i])
        {
            div2 = i;
            break;
        }
    }


    int ans = div1 * div2;
    cout << ans;
}

int32_t main()
{
    fastio;
    generate();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
