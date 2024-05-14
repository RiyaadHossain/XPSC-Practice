#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto getSPF = [&](int num)
    {
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return i;
        }
        return 0ll;
    };

    vector<int> spf[32];
    for (int i = 0; i < n; i++)
    {
        int pf = getSPF(arr[i]);
        spf[pf].push_back(i);
    }

    int color = 0;
    vector<int> colored(n);
    for (int i = 0; i < 32; i++)
    {
        if (spf[i].size() == 0)
            continue;
        color++;
        for (int it : spf[i])
            colored[it] = color;
    }

    cout << color << endl;
    for (int it : colored)
        cout << it << " ";
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
