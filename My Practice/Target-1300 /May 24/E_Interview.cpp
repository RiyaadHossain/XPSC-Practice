#include <bits/stdc++.h>
using namespace std;

// #define endl '\n'
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

    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    auto ok = [&](int left, int mid)
    {
        cout << "? " << mid - left + 1 << " ";
        for (int i = left; i <= mid; i++)
            cout << arr[i] << " ";
        cout << endl;

        int x;
        cin >> x;
        int sum = prefix[mid] - (left == 0 ? 0 : prefix[left - 1]);

        return sum == x;
    };

    int ans = 0;
    int left = 0, right = n, mid;
    while (left < right)
    {
        mid = (left + right) / 2;

        if (ok(left, mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
    }

    cout << "! " << left + 1;
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
        cout << endl;
    }

    return 0;
}