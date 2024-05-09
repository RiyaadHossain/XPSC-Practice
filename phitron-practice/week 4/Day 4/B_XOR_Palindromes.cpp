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
    int n;
    cin >> n;

    string str;
    cin >> str;

    int arr[n];
    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = str[i] - '0';
        if (arr[i] == 1)
            ones++;
        else
            zeros++;
    }

    int changes = 0;
    for (int i = 0; i < n / 2; i++)
        changes += (arr[i] != arr[n - 1 - i]);

    int odd = n % 2;
    for (int i = 0; i <= n; i++)
    {
        bool isOk = 0;
        if (i > changes)
        {
            int tmp = i;
            tmp -= changes;
            if ((tmp & 1) && odd)
                tmp--;
            if (tmp <= n - changes * 2)
                tmp -= ((tmp / 2) * 2);
            if (tmp == 0)
                isOk = 1;
        }

        if (i == ones || i == zeros || i == changes || i == (n - changes) || isOk)
            cout << 1;
        else
            cout << 0;
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
