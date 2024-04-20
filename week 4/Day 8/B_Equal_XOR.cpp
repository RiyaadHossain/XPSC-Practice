#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

// const int N = (5 * 1e4) + 1;

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

    int N = 2 * n + 1;

    int arr[N];
    vector<int> freq(N);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> arr[i];
        if (i < n)
            freq[arr[i]]++;
    }

    vector<int> twiceCnt1, twiceCnt2, onceCnt;
    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 2)
            twiceCnt1.push_back(i);
        else if (freq[i] == 1)
            onceCnt.push_back(i);
        else
            twiceCnt2.push_back(i);
    }

    vector<int> result1, result2;
    for (int i = 0; i < twiceCnt1.size(); i++)
    {
        if (i == k)
            break;
        result1.push_back(twiceCnt1[i]), result1.push_back(twiceCnt1[i]);
        result2.push_back(twiceCnt2[i]), result2.push_back(twiceCnt2[i]);
    }

    for (int i = 0; i < onceCnt.size(); i++)
    {
        if (result1.size() == 2 * k)
            break;
        result1.push_back(onceCnt[i]);
        result2.push_back(onceCnt[i]);
    }

    for (int it : result1)
        cout << it << " ";
    cout << endl;
    for (int it : result2)
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
