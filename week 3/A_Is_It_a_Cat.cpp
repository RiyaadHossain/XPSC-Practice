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

char lowercase(char ch)
{
    if (ch <= 90)
        return ch + 32;
    return ch;
}

bool isSame(char a, char b)
{
    a = lowercase(a), b = lowercase(b);
    return a == b;
}

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    string meow;
    meow.push_back(lowercase(str[0]));
    for (int i = 1; i < n; i++)
    {
        if (!isSame(meow.back(), str[i]))
            meow.push_back(lowercase(str[i]));
    }

    string meo = "meow";
    cout << (meow == meo ? ye : no);
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
