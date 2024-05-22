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
    priority_queue<int> mxHeap;
    priority_queue<int, vector<int>, greater<int>> mnHeap;
    for (int i = 0; i < n; i++)
        cin >> arr[i], mxHeap.push(arr[i]), mnHeap.push(arr[i]);

    int mx1 = mxHeap.top(), mn1 = mnHeap.top();
    mxHeap.pop(), mnHeap.pop();
    int mx2 = mxHeap.top(), mn2 = mnHeap.top();

    int ans = abs(mx1 - mn1) + abs(mn1 - mx2) + abs(mx2 - mn2) + abs(mn2 - mx1);
    cout << ans;
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
