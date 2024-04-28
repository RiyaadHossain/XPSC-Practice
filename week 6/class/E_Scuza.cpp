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
    int n, q;
    cin >> n >> q;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    vector<int> maxPrefix(n);
    maxPrefix[0] = arr[0];
    for (int i = 1; i < n; i++)
        maxPrefix[i] = max(maxPrefix[i - 1], arr[i]);

    auto search = [&](int key)
    {
        int left = 0, right = n - 1, mid, ans = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (maxPrefix[mid] <= key)
                ans = mid, left = mid + 1;
            else
                right = mid - 1;
        }

        return ans;
    };

    int x, idx;
    while (q--)
    {
        cin >> x;
        idx = search(x);
        cout << (idx == -1 ? 0 : prefix[idx]) << " ";
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
