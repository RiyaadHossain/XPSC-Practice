#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ye cout << "Yes"
#define no cout << "No"
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

    map<int, int> mpp;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i], mpp[arr[i]]++;

    int mex = 0;
    for (int i = 0; i <= n; i++)
    {
        if (mpp.count(i) == 0)
        {
            mex = i;
            break;
        }
    }

    if (mex == n)
    {
        no;
        return;
    }

    if (!mpp.count(mex + 1))
    {
        ye;
        return;
    }

    int target = mex + 1;
    int st = -1, en;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            if (st == -1)
                st = i;
            en = i;
        }
    }

    int cnt = 0;
    for (int i = st; i <= en; i++)
    {
        mpp[arr[i]]--;
        if (arr[i] < target && mpp[arr[i]] == 0)
        {
            no;
            return;
        }
    }

    ye;
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