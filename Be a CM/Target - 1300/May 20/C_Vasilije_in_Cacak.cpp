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

vector<int> sum(1e6);

void solve()
{
    int n, k, x;
    cin >> n >> k >> x;

    int op1 = sum[k], op2 = sum[n] - sum[n - k];
    if (x >= op1 && x <= op2)
        ye;
    else
        no;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        cnt += i;
        sum[i] = cnt;
    }

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}