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

    string s;
    cin >> s;

    vector<int> alpha(26);
    for (int i = 0; i < n; i++)
        alpha[s[i] - 'a']++;

    string s2;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i])
            s2.push_back('a' + i);
    }

    int m = s2.size();
    map<char, char> mpp;
    for (int i = 0; i < m; i++)
        mpp[s2[i]] = s2[m - i - 1];

    for (int i = 0; i < n; i++)
        cout << mpp[s[i]];
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