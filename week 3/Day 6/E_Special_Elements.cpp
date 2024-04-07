#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> arr;
bool isSpecial(int val, int st, int end)
{
    if (st == -1 || st == arr.size())
        return 0;

    int i = st, j = i + 1;
    int sum = arr[i];
    while (j <= end)
    {
        sum += arr[j];
        while (sum > val)
            sum -= arr[i++];

        if (j - i >= 1 && val == sum)
            return 1;
        j++;
    }

    return 0;
}

void solve()
{
    int n;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (isSpecial(arr[i], 0, i - 1) || isSpecial(arr[i], i + 1, n - 1))
            ans++;
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
