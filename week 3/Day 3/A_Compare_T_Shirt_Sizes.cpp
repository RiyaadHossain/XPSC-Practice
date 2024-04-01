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

void solve()
{
    string size1, size2;
    cin >> size1 >> size2;

    int n = size1.size(), m = size2.size();
    char ch1 = size1[n - 1];
    char ch2 = size2[m - 1];
    if (ch1 == ch2)
    {
        if (n == m)
            cout << '=';
        else if (ch1 == 'L')
            cout << (n < m ? '<' : '>');
        else
            cout << (n < m ? '>' : '<');
    }
    else
        cout << (ch1 < ch2 ? '>' : '<');
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
