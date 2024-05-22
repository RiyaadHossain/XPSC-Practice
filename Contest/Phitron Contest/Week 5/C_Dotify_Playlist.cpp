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
    int n, k, l;
    cin >> n >> k >> l;

    vector<int> arr;
    int song, lan;
    ll sum = 0;
    while (n--)
    {
        cin >> song >> lan;
        if (lan == l)
            arr.push_back(song);
    }

    if (arr.size() < k)
    {
        cout << -1;
        return;
    }

    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < k; i++)
        sum += arr[i];

    cout << sum;
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
