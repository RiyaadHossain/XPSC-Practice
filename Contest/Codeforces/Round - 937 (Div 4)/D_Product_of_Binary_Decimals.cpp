#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"

const int N = 1e5 + 5;

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> bin;
void generateBinary()
{
    string s;
    for (int i = 2; i <= N; i++)
    {
        s = to_string(i);
        if (*max_element(s.begin(), s.end()) == '1')
            bin.push_back(i);
    }
}

vector<int> binaryProduct(N);
void fillBnProduct()
{
    binaryProduct[1] = 1;
    for (int i = 1; i < N; i++)
    {
        if (binaryProduct[i])
        {
            for (int it : bin)
            {
                if (i * it >= N)
                    break;
                binaryProduct[i * it] = 1;
            }
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    if (binaryProduct[n])
        cout << ye;
    else
        cout << no;
}

int32_t main()
{
    fastio;
    generateBinary();
    fillBnProduct();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
