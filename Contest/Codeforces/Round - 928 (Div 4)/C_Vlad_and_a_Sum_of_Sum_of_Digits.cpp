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

vector<ll> arr;
int sum(int num)
{
    int sum = 0;
    while (num)
    {
        sum += (num % 10);
        num /= 10;
    }

    return sum;
}

void solve()
{
    int n;
    cin >> n;

    cout << arr[n - 1];
}

int32_t main()
{
    fastio;

    int n = 2 * 1e5 + 5;
    arr.resize(n);
    arr[0] = 1;
    for (int i = 1; i < n; i++)
        arr[i] = arr[i - 1] + sum(i + 1);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
