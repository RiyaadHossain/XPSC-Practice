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

bool isValid(string &str, char ch1, char ch2, char ch3)
{
    stack<char> st, st2;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ch1)
            st.push('.');
        else if (!st.empty())
            st.pop();

        if (str[i] == ch2 || str[i] == ch3)
            st2.push('.');
        else if (!st2.empty())
            st2.pop();
    }

    return st.empty() || st2.empty();
}

void solve()
{
    string str;
    cin >> str;

    int a = 0, b = 0, c = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'A')
            a++;
        if (str[i] == 'B')
            b++;
        if (str[i] == 'C')
            c++;
    }

    bool ans = 0;
    if (a + b == c)
        ans = isValid(str, 'C', 'A', 'B');
    if (b + c == a)
        ans = isValid(str, 'A', 'C', 'B') || ans;
    if (a + c == b)
        ans = isValid(str, 'B', 'A', 'C') || ans;

    cout << (ans ? ye : no);
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
