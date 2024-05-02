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

void solve()
{
    int n, m;
    cin >> n;

    int boy[n];
    for (int i = 0; i < n; i++)
        cin >> boy[i];

    cin >> m;
    int girl[m];
    for (int i = 0; i < m; i++)
        cin >> girl[i];

    sort(boy, boy + n);
    sort(girl, girl + m);

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m)
    {
        if (abs(boy[i] - girl[j]) <= 1)
            ans++;

        if (abs(boy[i] - girl[j]) <= 1)
            i++, j++;
        else if (boy[i] < girl[j])
            i++;
        else
            j++;
    }

    cout << ans;
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
