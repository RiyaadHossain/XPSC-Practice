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

    sort(arr, arr + n);

    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (sum < arr[i])
            ans.push_back(arr[i]), sum += arr[i], arr[i] = 0;
    }

    cout << n - ans.size() << endl;
    for (int it : ans)
        cout << it << " ";

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
            cout << arr[i] << " ";
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
