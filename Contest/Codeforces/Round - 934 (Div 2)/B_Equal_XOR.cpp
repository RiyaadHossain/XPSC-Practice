#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
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

    int x;
    vector<int> track(n + 1);
    for (int i = 0; i < n * 2; i++)
    {
        cin >> x;
        if (i < n)
            track[x]++;
    }

    vector<int> twice1, once, twice2;
    for (int i = 1; i <= n; i++)
    {
        if (track[i] == 2)
            twice1.push_back(i);
        else if (track[i] == 1)
            once.push_back(i);
        else
            twice2.push_back(i);
    }

    int i = 0;
    vector<int> left, right;

    while (i < twice1.size() && left.size() < k * 2)
        left.push_back(twice1[i]), left.push_back(twice1[i++]);

    i = 0;
    while (left.size() < k * 2)
        left.push_back(once[i]), right.push_back(once[i]), i++;

    i = 0;
    while (right.size() < k * 2)
        right.push_back(twice2[i]), right.push_back(twice2[i++]);

    for (int it : left)
        cout << it << " ";
    cout << endl;
    for (int it : right)
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
