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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    if (n < 4 || m < 4 || (n + m) < 11)
    {
        cout << -1;
        return;
    }

    sort(arr1.rbegin(), arr1.rend());
    sort(arr2.rbegin(), arr2.rend());

    int ans = 0;
    for (int i = 0; i < 4; i++)
        ans += (arr1[i] + arr2[i]);

    int it = 1, i = 4, j = 4;
    while (it <= 3)
    {
        if (i < n && j < m)
        {
            if (arr1[i] > arr2[j])
                ans += arr1[i++];
            else
                ans += arr2[j++];
        }
        else if (i < n)
            ans += arr1[i++];
        else if (j < m)
            ans += arr2[j++];
        it++;
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
