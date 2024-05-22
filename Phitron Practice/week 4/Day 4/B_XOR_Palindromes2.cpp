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
        arr[i] = str[i] - '0';

    int pair = 0, buggish = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[n - 1 - i])
            pair += 2;
        else
            buggish++;
    }

    int ext = n & 1;
    for (int i = 0; i <= n; i++)
    {
        int tmp = i;
        if (tmp < buggish)
        {
            cout << 0;
            continue;
        }

        tmp -= buggish;
        if ((tmp & 1) && ext)
            tmp--;

        if (tmp <= pair)
            tmp -= ((tmp / 2) * 2);

        if (tmp == 0)
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
