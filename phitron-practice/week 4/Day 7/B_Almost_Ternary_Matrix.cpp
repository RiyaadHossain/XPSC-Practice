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

vector<int> pattern1, pattern2;
void generatePattern()
{
    int track = 1;
    for (int i = 0; i <= 50; i++)
    {
        if (track)
            pattern1.push_back(0), pattern1.push_back(1);
        else
            pattern1.push_back(1), pattern1.push_back(0);

        if (track)
            pattern2.push_back(1), pattern2.push_back(0);
        else
            pattern2.push_back(0), pattern2.push_back(1);

        track ^= 1;
    }
}

void printPattern(bool pattern, int m)
{
    if (pattern)
    {
        for (int i = 0; i < m; i++)
            cout << pattern1[i] << " ";
        cout << endl;
        for (int i = 0; i < m; i++)
            cout << pattern2[i] << " ";
    }
    else
    {
        for (int i = 0; i < m; i++)
            cout << pattern2[i] << " ";
        cout << endl;
        for (int i = 0; i < m; i++)
            cout << pattern1[i] << " ";
    }
    cout << endl;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    int track = 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (track)
            printPattern(0, m);
        else
            printPattern(1, m);

        track ^= 1;
    }
}

int32_t main()
{
    fastio;
    generatePattern();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
