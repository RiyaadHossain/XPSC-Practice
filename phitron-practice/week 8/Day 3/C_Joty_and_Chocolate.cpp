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


int lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}

int getCM(int a, int b, int range)
{
    int lcm_ab = lcm(a, b);
    int count = range / lcm_ab;

    return count;
}

void solve()
{
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    int result = (n / a) * p + (n / b) * q;
    result -= getCM(a, b, n) * min(p, q);
    cout << result;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
