#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2 * 1e5 + 5;
vector<vector<int>> divi(N);
void fillDiv()
{
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
            divi[j].push_back(i);
    }
}

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    for (int it : divi[n])
    {
        int cnt = 0;
        for (int i = it; i < n && cnt <= 1; i++)
            cnt += (str[i] != str[i % it]);

        if (cnt <= 1)
        {
            cout << it;
            return;
        }

        cnt = 0;
        for (int i = it * 2; i < n && cnt <= 1; i++)
            cnt += (str[i] != str[it + i % it]);
        for (int i = 0; i < it && cnt <= 1; i++)
            cnt += (str[i] != str[it + i]);

        if (cnt <= 1)
        {
            cout << it;
            return;
        }
    }

    cout << n;
}

int32_t main()
{
    fastio;
    fillDiv();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
