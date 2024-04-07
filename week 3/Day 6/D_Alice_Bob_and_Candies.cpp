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
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = n - 1;
    int candyEaten = 0, moves = 0, cnt = 0;
    int alice = 0, bob = 0;
    while (i <= j && j >= i)
    {
        cnt = 0;
        if (moves % 2 == 0)
        {
            while (i <= j && cnt <= candyEaten)
                cnt += arr[i++];
            alice += cnt;
        }
        else
        {
            while (j >= i && cnt <= candyEaten)
                cnt += arr[j--];
            bob += cnt;
        }
        candyEaten = cnt;
        moves++;
    }

    cout << moves << " " << alice << " " << bob;
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
