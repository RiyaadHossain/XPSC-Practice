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

// Looping Mechanism
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)
#define forEach(x, ds) for (auto &x : ds)

// Shortcut functions
#define a first
#define b second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcount(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Type
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

void solve()
{
    int n, h;
    cin >> n >> h;

    vi a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    auto abosorve = [&](int num1, int num2, int num3) -> int
    {
        int tmp = 0, hum = h;
        forr(i, 0, n - 1)
        {
            while (hum <= a[i] && (num1 || num2 || num3))
            {
                if (num1)
                    hum *= num1, num1 = 0;
                else if (num2)
                    hum *= num2, num2 = 0;
                else if (num3)
                    hum *= num3, num3 = 0;
            }

            if (hum > a[i])
                hum += (a[i] / 2), tmp++;
        }

        return tmp;
    };

    int ans = 0;
    ans = max(ans, abosorve(2, 2, 3));
    ans = max(ans, abosorve(2, 3, 2));
    ans = max(ans, abosorve(3, 2, 2));

    print(ans);
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