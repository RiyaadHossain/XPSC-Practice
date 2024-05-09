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

    int x;
    vector<int> freq(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
    }

    int c = 0;
    for (int i = 0; i <= n; i++)
    {
        c += (freq[i] == 1);
        if (c == 2 || freq[i] == 0)
        {
            cout << i;
            break;
        }
    }
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
