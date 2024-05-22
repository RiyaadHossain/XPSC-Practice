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

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result;
    int last = *max_element(arr, arr + n);

    map<int, bool> mpp;
    for (int i = 0; i < n; i++)
    {
        if (mpp[arr[i]] == 0)
            result.push_back(arr[i]);
        else
            result.push_back(last);

        mpp[arr[i]] = 1;
    }

    for (int it : result)
        cout << it << " ";
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
