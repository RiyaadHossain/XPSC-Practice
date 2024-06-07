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
const int N = 1e6;

set<int> st;
void generate()
{
    for (int i = 2; i < N / 2; i++)
    {
        int tmp = i * (i + 1) + 1;
        while (tmp < N)
            st.insert(tmp), tmp = (tmp * i) + 1;
    }
}

void solve()
{
    int n;
    cin >> n;

    bool ans = st.find(n) != st.end();
    ans ? ye : no;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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