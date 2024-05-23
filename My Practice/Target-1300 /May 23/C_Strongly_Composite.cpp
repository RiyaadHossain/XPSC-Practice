#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 2; j * j <= arr[i]; j++)
        {
            while (arr[i] % j == 0)
            {
                arr[i] /= j;
                mpp[j]++;
            }
        }
        if (arr[i] > 1)
            mpp[arr[i]]++;
    }

    int ans = 0, ex = 0;
    for (auto [x, y] : mpp)
        ans += (y / 2), ex += (y % 2);

    ans += (ex / 3);
    cout << ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}