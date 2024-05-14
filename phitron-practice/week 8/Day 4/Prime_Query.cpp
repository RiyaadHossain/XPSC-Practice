#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

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

    vector<int> one(n + 1), two(n + 1);
    one[1] = (arr[0] == 1), two[1] = (arr[0] == 2);
    for (int i = 2; i <= n; i++)
    {
        one[i] = one[i - 1] + (arr[i - 1] == 1);
        two[i] = two[i - 1] + (arr[i - 1] == 2);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;

        int oneCnt = one[r] - one[l - 1];
        int twoCnt = two[r] - two[l - 1];
        int rem = r + 1 - l - oneCnt - twoCnt;

        if (oneCnt < twoCnt)
            swap(oneCnt, twoCnt);

        int change = min({k, rem, oneCnt - twoCnt});
        twoCnt += change;
        k -= change;
        rem -= change;

        if (oneCnt == twoCnt)
        {
            int add = min(k, rem);
            oneCnt += (add / 2);
            twoCnt += (add + 1) / 2;
        }
        else
        {
            int diff = oneCnt - twoCnt;
            int add = min(k, diff / 2);
            oneCnt -= add;
            twoCnt += add;
        }

        int ans = oneCnt * twoCnt;
        cout << ans << endl;
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
