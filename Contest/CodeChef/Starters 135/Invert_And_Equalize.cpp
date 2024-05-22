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

    string str;
    cin >> str;

    int cnt1 = str[0] == '1', cnt2 = str[0] == '0';
    for (int i = 0; i < n - 1; i++)
    {
        cnt1 += (str[i] == '0' && str[i + 1] == '1');
        cnt2 += (str[i] == '1' && str[i + 1] == '0');
    }

    cout << min(cnt1, cnt2);
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