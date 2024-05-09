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
    int n;
    cin >> n;

    vector<string> letters(n);
    for (int i = 0; i < n; i++)
        cin >> letters[i];

    ll ans = 0;
    char ch1, ch2;
    map<string, int> mpp;
    vector<int> first(26, 0), second(26, 0);
    for (int i = 0; i < n; i++)
    {
        ch1 = letters[i][0], ch2 = letters[i][1];
        ll cnt = first[ch1 - 'a'] + second[ch2 - 'a'];

        string str;
        str.push_back(ch1), str.push_back(ch2);

        cnt -= (mpp[str] * 2);

        ans += cnt;

        first[ch1 - 'a']++, second[ch2 - 'a']++;
        mpp[str]++;
    }

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
