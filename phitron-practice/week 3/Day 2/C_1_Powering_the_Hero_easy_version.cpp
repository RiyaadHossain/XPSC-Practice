#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    priority_queue<int> qu;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && !qu.empty())
            ans += qu.top(), qu.pop();
        else if (arr[i] != 0)
            qu.push(arr[i]);
    }

    cout << ans;
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
