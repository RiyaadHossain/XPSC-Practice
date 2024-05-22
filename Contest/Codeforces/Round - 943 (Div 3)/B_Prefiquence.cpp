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
    int n, m;
    cin >> n >> m;

    string str1, str2;
    cin >> str1 >> str2;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
        while (i < n && j < m && str1[i] == str2[j])
            i++, j++;

        while (j < m && str1[i] != str2[j])
            j++;
    }

    cout << i;
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
