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
    int n, k;
    cin >> n >> k;

    vector<int> div;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            div.push_back(i);
            if (n / i != i)
                div.push_back(n / i);
        }
    }

    if (div.size() < k)
    {
        cout << -1;
        return;
    }

    sort(div.begin(), div.end());
    cout << div[k - 1];
}

int32_t main()
{
    fastio;

    solve();
    cout << '\n';

    return 0;
}
