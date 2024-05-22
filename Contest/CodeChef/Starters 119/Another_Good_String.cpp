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
    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    int mx = 0;
    int i = 0, j, cnt;
    while (i < n)
    {
        j = i;
        cnt = 0;
        while (j < n && str[i] == str[j])
            cnt++, j++;
        mx = max(mx, cnt);
        i = j;
    }

    i = n - 1;
    int lastCnt = 0;
    char last = str[n - 1];
    while (i >= 0 && last == str[i])
        lastCnt++, i--;

    cout << mx << " ";

    char ch;
    while (q--)
    {
        cin >> ch;
        if (last == ch)
            lastCnt++;
        else
            lastCnt = 1;
        mx = max(mx, lastCnt);
        last = ch;
        cout << mx << " ";
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
