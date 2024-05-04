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

    string str;
    cin >> str;

    auto check = [&](char ch)
    {
        string tmp;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != ch)
                tmp.push_back(str[i]);
        }
        string tmp2 = tmp;
        reverse(tmp.begin(), tmp.end());

        return tmp == tmp2;
    };

    auto operation = [&](char ch)
    {
        int op = 0;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (str[i] == str[j])
            {
                i++, j--;
                continue;
            }

            op++;
            if (str[i] == ch)
                i++;
            else
                j--;
        }

        return op;
    };

    char ch1 = '-', ch2 = '-';
    for (int i = 0; i < n; i++)
    {
        if (str[i] != str[n - 1 - i])
            ch1 = str[i], ch2 = str[n - 1 - i];
    }

    if (ch1 == '-')
    {
        cout << 0;
        return;
    }

    bool poss1 = 0, poss2 = 0;
    poss1 = check(ch1), poss2 = check(ch2);

    if (!poss1 && !poss2)
    {
        cout << -1;
        return;
    }

    int op = 1e9;
    if (poss1)
        op = operation(ch1);
    if (poss2)
        op = min(op, operation(ch2));

    cout << op;
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
