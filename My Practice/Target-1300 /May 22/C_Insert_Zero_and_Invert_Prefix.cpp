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

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    if (a[n - 1] == 1)
    {
        no;
        return;
    }

    ye;
    cout << endl;

    int st = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            cout << 0 << " ";
        else
        {
            if (i == 0)
                cout << st << " ";
            else if (a[i - 1] == 0)
                cout << st << " ", st = 1;
            else
                cout << 0 << " ", st++;
        }
    }
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