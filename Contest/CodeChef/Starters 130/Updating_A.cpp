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

int maxNegSum(int *arr, int n)
{
    int ans = 0, curr = arr[1];
    for (int i = 2; i <= n; i++)
    {
        ans = min(ans, curr + arr[i]);
        curr = min(arr[i] + curr, arr[i]);
    }

    return ans;
}

void solve()
{
    int n;
    cin >> n;

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    /*
        # Observation:
        Alice - make as much as negative sum to positive
        Bob - merge the ramaing negative with total sum

        Alice have only one chance because on Bob's first move, he will merge all the remaining negatives.
        So, Alice will choose the maximum negative subarray. Also, Bob won't be able to decrease anything to the sum of the array. But Alice have the ability to increase the sum by making absolute the biggest negative subarray.

        # Conclusion:
        This problem now reduce to -> find the maximum negative subarray sum.
    */

    int maxSum = -1e18;
    vector<int> prefix(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];

        if (i - 2 >= 0)
            maxSum = max(maxSum, prefix[i - 2]);
        ans = min(ans, prefix[i] - maxSum);
    }

    // Another way of finding maximum negative sum -> maxNegSum(arr, n) [above solve function]

    int sum = prefix[n];
    cout << (sum - 2 * ans);
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
