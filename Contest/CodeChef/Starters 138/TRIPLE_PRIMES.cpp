#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n'
#define ye cout << "Yes"
#define no cout << "No"
#define int long long
#define print(...) cout << (__VA_ARGS__)
#define println(...) cout << (__VA_ARGS__) << '\n'

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

vi primes;
void generate()
{
    for (int i = 2; i <= 1e5; i++)
    {
        bool isPrime = 1;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
                break;
            }
        }

        if (isPrime)
            primes.pb(i);
    }
}

void solve()
{
    int n;
    cin >> n;

    int m = sz(primes);
    for (int i = 1; i < m; i++)
    {
        int a = primes[i] * primes[i];
        if (a + 4 >= n)
            break;

        int rem = n - (a + 4);
        int sqr = sqrt(rem);
        if (sqr != primes[i] && sqr * sqr == rem && binary_search(all(primes), sqr))
        {
            ye;
            return;
        }
    }

    no;
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