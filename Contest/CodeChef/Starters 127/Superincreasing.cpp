#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = (2 * 1e5) + 5;

vector<ll> arr;
void solve()
{
    ll n, k, x;
    cin >> n >> k >> x;

    if (k >= 50)
    {
        cout << "No";
        return;
    }

    cout << (x >= arr[k - 1] ? "Yes" : "No");
}

int32_t main()
{

    arr.resize(N);
    arr[0] = 1;
    ll sum = 1;
    for (int i = 1; i < N; i++)
    {
        arr[i] = sum + 1;
        sum += arr[i];
    }

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
