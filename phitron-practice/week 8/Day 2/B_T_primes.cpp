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

const int N = 1e6 + 5;
vector<bool> seive(N, 1);
void generateSeive()
{
    for (int i = 2; i < N; i++)
    {
        if (seive[i])
        {
            for (int j = i + i; j < N; j += i)
                seive[j] = 0;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] <= 3)
        {
            no;
            cout << endl;
            continue;
        }

        int sq = sqrt(arr[i]);
        if (sq * sq == arr[i] && seive[sq])
            ye;
        else
            no;
        cout << endl;
    }
}

int32_t main()
{
    fastio;
    generateSeive();

    solve();
    cout << '\n';

    return 0;
}
