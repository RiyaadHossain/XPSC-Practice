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

    int arr[n], idx;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == n)
            idx = i;
    }

    idx = (idx % 2 == 0 ? 0 : 1);
    vector<pii> a1, a2;
    for (int i = 0; i < n; i++)
    {
        if (idx == 0)
        {
            if (i % 2 == 0)
                a1.push_back({arr[i], i});
            else
                a2.push_back({arr[i], i});
        }
        else
        {
            if (i % 2)
                a1.push_back({arr[i], i});
            else
                a2.push_back({arr[i], i});
        }
    }

    sort(all(a1));
    sort(a2.rbegin(), a2.rend());

    int it = n;
    vector<int> ans(n);
    for (pii i : a1)
        ans[i.second] = it--;

    it = 1;
    for (pii i : a2)
        ans[i.second] = it++;

    for (int i : ans)
        cout << i << " ";
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