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

bool isHash(int i, int j)
{
    if (
        (i % 4 == 0 && j % 4 == 0) ||
        (i % 4 == 0 && j % 4 == 1) ||
        (i % 4 == 1 && j % 4 == 0) ||
        (i % 4 == 1 && j % 4 == 1))
        return 1;

    if (
        (i % 4 == 2 && j % 4 == 2) ||
        (i % 4 == 2 && j % 4 == 3) ||
        (i % 4 == 3 && j % 4 == 2) ||
        (i % 4 == 3 && j % 4 == 3))
        return 1;

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    for (int i = 0; i < n * 2; i++)
    {
        for (int j = 0; j < n * 2; j++)
        {
            if (isHash(i, j))
                cout << '#';
            else
                cout << '.';
        }
        cout << endl;
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
    }

    return 0;
}
