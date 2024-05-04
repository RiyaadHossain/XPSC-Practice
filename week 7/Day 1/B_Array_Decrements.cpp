#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES\n";
#define no cout << "NO\n";
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve(int t)
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int bis0 = 0;
    vector<int> diff = vector<int>();
    for (int i = 0; i < n; i++)
    {
        if (b[i] != 0)
            diff.push_back(a[i] - b[i]);
        else
            bis0 = max(bis0, a[i] - b[i]);
    }

    if (!diff.empty() && (diff[0] < 0 || bis0 > diff[0]))
    {
        no;
        return;
    }

    for (int i = 0; i < diff.size(); i++)
    {
        if (i < diff.size() - 1 && diff[i] != diff[i + 1])
        {
            no;
            return;
        }
    }

    ye;
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    int i = 1;
    while (i <= t)
    {
        solve(i);
        cout << '\n';
        i++;
    }

    return 0;
}
