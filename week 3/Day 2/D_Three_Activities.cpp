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

    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int arr2[n];
    for (int i = 0; i < n; i++)
        cin >> arr2[i];

    int arr3[n];
    for (int i = 0; i < n; i++)
        cin >> arr3[i];

    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = max({arr1[i], arr2[i], arr3[i]});

    sort(arr, arr + n, greater<int>());
 
    cout << arr[0] << endl;
    cout << arr[1] << endl;
    cout << arr[2] << endl;

    cout << arr[0] + arr[1] + arr[2];
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
