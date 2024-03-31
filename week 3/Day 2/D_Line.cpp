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

    string str;
    cin >> str;

    int sum = 0;
    int people[n];
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'L')
            people[i] = i - 0;
        else
            people[i] = n - i - 1;
        sum += people[i];
    }

    vector<pii> more;
    int xsum = 0;
    for (int i = 0; i < n; i++)
    {
        int mx = max(i - 0, n - i - 1);
        if (mx != people[i])
            more.push_back({mx, people[i]}), xsum += people[i];
    }

    sort(more.rbegin(), more.rend());

    int m = more.size();

    pii prefix[m];
    if (m)
        prefix[0] = more[0];
    for (int i = 1; i < m; i++)
        prefix[i] = {prefix[i - 1].first + more[i].first, prefix[i - 1].second + more[i].second};

    for (int i = 1; i <= n; i++)
    {
        if (i > m)
            cout << sum + (m ? prefix[m - 1].first - xsum : 0) << " ";
        else
            cout << sum + (m ? prefix[i - 1].first - prefix[i - 1].second : 0) << " ";
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
