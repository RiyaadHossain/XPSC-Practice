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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j * j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                while (arr[i] % j == 0)
                {
                    mpp[j]++;
                    arr[i] /= j;
                }
            }
        }
        if (arr[i] > 1)
            mpp[arr[i]]++;
    }

    for (auto [x, y] : mpp)
    {
        if (y % n)
        {
            no;
            return;
        }
    }

    ye;
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
