#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (3 * 1e5) + 1;

vector<int> XORs(N);
void generateXOR()
{
    int XOR = 0;
    for (int i = 0; i <= N; i++)
    {
        XORs[i] = XOR;
        XOR ^= i;
    }
}

void solve()
{
    int a, b;
    cin >> a >> b;

    int XOR = XORs[a];

    if (XOR != b)
    {
        if ((XOR ^ b) == a)
            cout << a + 2;
        else
            cout << a + 1;
        return;
    }

    cout << a;
}

int32_t main()
{
    fastio;
    generateXOR();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
