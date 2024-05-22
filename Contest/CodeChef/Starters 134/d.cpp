#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const ll llinf = 1e18;

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define a first
#define b second
#define ins insert
#define lb lower_bound // First element NOT LESS than val
#define ub upper_bound // First element GREATER than val

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i < (b); ++i)
#define rforr(i, a, b) for (int i = (a); i > (b); --i)
#define forEach(x, vec) for (auto &x : vec)

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    int answer[n + 1];
    answer[0] = a[0];

    multiset<int> mn, rem;
    int sum = a[0];
    rem.insert(a[0]);

    for (int i = 1; i < n; i++)
    {
        rem.insert(a[i]);
        sum += a[i];

        if (i % 2 == 0)
        {
            auto it = rem.begin();
            sum -= 2 * (*it);
            mn.insert(*it);
            rem.erase(it);
            answer[i] = sum;
        }
        else if (mn.size() && *rem.begin() < *mn.rbegin())
        {
            int x = *rem.begin();
            int y = *mn.rbegin();
            sum += 2 * y;
            sum -= 2 * x;
            rem.insert(y), mn.insert(x);
            rem.erase(rem.find(x));
            mn.erase(mn.find(y));
        }
    }

    while (q--)
    {
        int k;
        cin >> k;
        k--;

        cout << answer[k] << ' ';
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