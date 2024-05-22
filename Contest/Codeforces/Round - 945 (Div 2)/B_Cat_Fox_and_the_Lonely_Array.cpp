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

    int x = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i], x |= arr[i];

    vector<int> check(20);
    for (int i = 0; i < 20; i++)
    {
        if (x & (1 << i))
            check[i] = 1;
    }

    vector<int> tmp(20);
    auto add = [&](int idx)
    {
        for (int i = 0; i < 20; i++)
        {
            if (arr[idx] & (1 << i))
                tmp[i]++;
        }
    };
    auto remove = [&](int idx)
    {
        for (int i = 0; i < 20; i++)
        {
            if ((arr[idx] & (1 << i)) && tmp[i])
                tmp[i]--;
        }
    };

    auto checker = [&]()
    {
        for (int i = 0; i < 20; i++)
        {
            if (check[i] && !tmp[i])
                return false;
        }

        return true;
    };

    int ans = 1, curr = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        curr |= arr[i];
        if (curr == x)
        {
            ans = n - i;
            break;
        }
    }

    int i = 0, j = 0;
    while (j < n)
    {
        add(j);
        while (checker() && i <= j)
        {
            ans = max(ans, j + 1 - i);
            remove(i);
            i++;
        }
        j++;
    }

    cout << ans;
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