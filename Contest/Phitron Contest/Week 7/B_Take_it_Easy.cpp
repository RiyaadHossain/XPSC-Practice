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

    int sum = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i], sum += arr[i];

    if (sum % n != 0)
    {
        no;
        return;
    }

    int avg = sum / n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > avg && ((arr[i] - avg) % 2))
        {
            no;
            return;
        }
        if (arr[i] < avg && ((avg - arr[i]) % 2))
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
