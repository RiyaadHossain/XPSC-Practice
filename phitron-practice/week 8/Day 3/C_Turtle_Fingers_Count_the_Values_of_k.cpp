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
    int a, b, l;
    cin >> a >> b >> l;

    set<int> st;
    int val1 = 1;
    for (int i = 0; i < 20 && val1 <= l; i++)
    {
        int val2 = 1;
        for (int j = 0; j < 20 && val1 * val2 <= l; j++)
        {
            if (l % (val1 * val2) == 0)
                st.insert(l / (val1 * val2));
            val2 *= b;
        }
        val1 *= a;
    }

    cout << st.size();
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
