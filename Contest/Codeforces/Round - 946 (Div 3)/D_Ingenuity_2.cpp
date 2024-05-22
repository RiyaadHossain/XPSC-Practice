#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    stack<int> N, S, E, W;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'N')
            N.push(i);
        if (str[i] == 'S')
            S.push(i);
        if (str[i] == 'E')
            E.push(i);
        if (str[i] == 'W')
            W.push(i);
    }

    int sz1 = sz(N), sz2 = sz(S), sz3 = sz(E), sz4 = sz(W);

    if ((sz1 + sz2) % 2 || (sz3 + sz4) % 2)
    {
        no;
        return;
    }

    vector<string> check = {"SN", "NS", "EW", "WE"};
    for (int i = 0; i < 4; i++)
    {
        if (check[i] == str)
        {
            no;
            return;
        }
    }

    vector<char> ans(n);
    stack<int> tmp1, tmp2;

    int x = abs(sz1 - sz2) / 2;
    tmp1 = N, tmp2 = S;
    if (sz1 == sz2 && sz1)
    {
        ans[tmp1.top()] = 'R', tmp1.pop();
        ans[tmp2.top()] = 'R', tmp2.pop();
        x = 0;
    }

    if (sz1 < sz2)
        tmp1 = S, tmp2 = N;
    while (x--)
        ans[tmp1.top()] = 'R', tmp1.pop();
    while (!tmp1.empty())
        ans[tmp1.top()] = 'H', tmp1.pop();
    while (!tmp2.empty())
        ans[tmp2.top()] = 'H', tmp2.pop();

    x = abs(sz3 - sz4) / 2;
    tmp1 = E, tmp2 = W;
    if (sz3 == sz4 && sz3)
    {
        ans[tmp1.top()] = 'H', tmp1.pop();
        ans[tmp2.top()] = 'H', tmp2.pop();
        x = 0;
    }

    if (sz3 < sz4)
        tmp1 = W, tmp2 = E;
    while (x--)
        ans[tmp1.top()] = 'H', tmp1.pop();
    while (!tmp1.empty())
        ans[tmp1.top()] = 'R', tmp1.pop();
    while (!tmp2.empty())
        ans[tmp2.top()] = 'R', tmp2.pop();

    for (char it : ans)
        cout << it;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}