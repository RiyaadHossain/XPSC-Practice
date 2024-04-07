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

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[j] == arr[i])
            j++;

        if ((i == 0 || arr[i] < arr[i - 1]) && (j > n - 1 || arr[j - 1] < arr[j]))
            cnt++;

        if (i < j)
            i = j - 1;
    }

    cout << (cnt == 1 ? ye : no);
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
