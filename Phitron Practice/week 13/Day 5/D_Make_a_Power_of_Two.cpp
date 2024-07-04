#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)

// Data Type
typedef vector<int> vi;
typedef pair<int, int> pii;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

vector<string> powOfTwo;
void generate()
{
    int n = 1;
    while (n <= llinf)
        powOfTwo.pb(to_string(n)), n *= 2;
}

void solve()
{
    string num;
    cin >> num;

    int ans = inf;
    for (string pot : powOfTwo)
    {
        int op = 0, j = 0, found = 0;
        int n = sz(pot), m = sz(num);
        for (int i = 0; i < n; i++)
        {
            while (j < m && pot[i] != num[j])
                op++, j++;

            if (j == m)
            {
                op += (n - i);
                break;
            }
            j++;
        }


        op += (m - j);

        ans = min(ans, op);
    }

    print(ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    generate();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}