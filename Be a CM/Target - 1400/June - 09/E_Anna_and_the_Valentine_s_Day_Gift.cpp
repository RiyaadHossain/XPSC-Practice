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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto get = [&](int num) -> pii
    {
        bool nonZero = 0;
        int tot = 0, zer = 0;
        while (num)
        {
            int x = num % 10;
            if (x == 0)
                zer += (!nonZero);
            else
                nonZero = 1;

            num /= 10;
            tot++;
        }

        return {tot - zer, zer};
    };

    int cnt = 0;
    vector<int> zeros;
    for (int i = 0; i < n; i++)
    {
        pii x = get(arr[i]);
        cnt += x.a;
        if (x.b)
            zeros.push_back(x.b);
    }


    sort(rall(zeros));
    for (int i = 1; i < sz(zeros); i+=2)
        cnt += zeros[i];

    cnt > m ? print("Sasha") : print("Anna");
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