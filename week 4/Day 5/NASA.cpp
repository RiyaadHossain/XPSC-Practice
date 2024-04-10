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

vector<int> palindromes;
bool isPalindrome(int x)
{

    string num = to_string(x);
    int n = num.size();

    for (int i = 0; i < n / 2; i++)
    {
        if (num[i] != num[n - 1 - i])
            return 0;
    }

    return 1;
}

void generate()
{
    int mx = 1 << 15;
    for (int i = mx; i >= 0; i--)
        if (isPalindrome(i))
            palindromes.push_back(i);
}

const int N = 1 << 15;

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    vector<int> ferq(N);
    for (int i = 0; i < n; i++)
        cin >> arr[i], ferq[arr[i]]++;

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < palindromes.size(); j++)
        {
            int exist = ferq[arr[i] ^ palindromes[j]];
            if (exist)
                ans += exist;
        }
        ferq[arr[i]]--;
    }

    cout << ans;
}

int32_t main()
{
    fastio;
    generate();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
