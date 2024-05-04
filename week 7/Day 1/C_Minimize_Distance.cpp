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
    int n, k;
    cin >> n >> k;

    int arr[n];

    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        if (arr[i] < 0)
            neg.push_back(abs(arr[i]));
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int ans = 0, posN, negN;
    posN = pos.size();
    for (int i = posN - 1; i >= 0; i -= k)
        ans += (pos[i] * (i < posN - 1 ? 2 : 1));

    negN = neg.size();
    for (int i = negN - 1; i >= 0; i -= k)
        ans += (neg[i] * (i < negN - 1 ? 2 : 1));

    if (negN && posN)
        ans += min(pos[posN - 1], neg[negN - 1]);
        
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
