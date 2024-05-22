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

int minOperation(string &str, char ch, int freq)
{
    int n = str.size();
    int preFreq[n];

    preFreq[0] = (str[0] == ch);
    for (int i = 1; i < n; i++)
        preFreq[i] = preFreq[i - 1] + (str[i] == ch);

    int mn = 1e8;
    for (int i = 0; i < n - freq; i++)
    {
        int curr = freq - (preFreq[i + freq - 1] - (i == 0 ? 0 : preFreq[i - 1]));
        mn = min(mn, curr);
    }

    return mn;
}

void solve()
{
    string str;
    cin >> str;

    vector<int> freq(26);
    for (int i = 0; i < str.size(); i++)
        freq[str[i] - 'a']++;

    int ans = 1e8;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
            ans = min(ans, minOperation(str, 'a' + i, freq[i]));
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
