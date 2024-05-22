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
    string str;
    cin >> str;

    int n = str.size();

    bool same = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[0] != str[i])
        {
            same = 0;
            break;
        }
    }

    if (same)
    {
        no;
    }
    else
    {
        for (int i = 1; i < n; i++)
        {
            if (str[i] != str[0])
            {
                swap(str[i], str[0]);
                break;
            }
        }

        ye;
        cout << endl;
        cout << str;
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
