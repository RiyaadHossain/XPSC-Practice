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
    string str;
    cin >> str;

    int n = str.size();

    int B = 0, b = 0;

    string result;
    for (int i = n - 1; i >= 0; i--)
    {
        if ('a' <= str[i] && str[i] <= 'z')
        {
            if (str[i] == 'b')
                b++;
            else if (b)
                b--;
            else
                result.push_back(str[i]);
        }
        else
        {
            if (str[i] == 'B')
                B++;
            else if (B)
                B--;
            else
                result.push_back(str[i]);
        }
    }

    reverse(result.begin(), result.end());
    cout << result;
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
