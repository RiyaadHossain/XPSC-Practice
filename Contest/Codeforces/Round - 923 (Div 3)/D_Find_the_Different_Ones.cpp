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
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int lastIdx[n];
    lastIdx[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] != arr[i + 1])
            lastIdx[i] = i + 1;
        else
            lastIdx[i] = lastIdx[i + 1];
    }

    int q;
    cin >> q;

    int l, r;
    while (q--)
    {
        cin >> l >> r;
        l--, r--;
        if (r >= lastIdx[l] && lastIdx[l] != -1)
            cout << l + 1 << " " << lastIdx[l] + 1;
        else
            cout << -1 << " " << -1;
        cout << endl;
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
