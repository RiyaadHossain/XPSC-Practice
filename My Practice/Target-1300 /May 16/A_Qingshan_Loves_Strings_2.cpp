#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "YES"
#define no cout << "NO"
#define int long long

// Shortcut functions
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
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
    int n;
    cin >> n;

    string str;
    cin >> str;

    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n; i++)
        cnt1 += (str[i] == '1'), cnt0 += (str[i] == '0');

    if (cnt1 != cnt0)
    {
        cout << -1;
        return;
    }

    int i = 0, j = n - 1;
    vector<int> result;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            i++, j--;
            continue;
        }

        if (str[i] == '0')
        {
            str.insert(j + 1, "01");
            result.push_back(j + 1);
            j += 2;
        }
        else
        {
            str.insert(i, "01");
            result.push_back(i);
            j += 2;
        }
    }

    cout << sz(result) << endl;
    for (int it : result)
        cout << it << " ";
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