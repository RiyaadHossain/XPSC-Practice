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
    int n;
    cin >> n;

    string plain, cipher;
    cin >> plain >> cipher;

    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        while (plain[i] != cipher[i])
        {
            cnt++;
            plain[i] += 3;
            if (plain[i] > 'Z')
                plain[i] = 'A' + (plain[i] - 'Z' - 1);
        }
        cout << cnt << " ";
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
