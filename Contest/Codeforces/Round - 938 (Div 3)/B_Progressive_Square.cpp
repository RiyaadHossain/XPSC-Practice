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

bool search(int *arr, int n, int key)
{
    bool ans = 0;
    int left = 0, right = n * n - 1, mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == key)
            return 1;

        if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return 0;
}

void solve()
{
    int n, c, d;
    cin >> n >> c >> d;

    multiset<int> st;
    int x;
    for (int i = 0; i < n * n; i++)
        cin >> x, st.insert(x);

    bool found = 0;
    int key;
    vector<vector<int>> mat(n, vector<int>(n));
    mat[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                key = *st.begin();
            else if (j == 0)
                key = mat[i - 1][j] + c;
            else
                key = mat[i][j - 1] + d;
            mat[i][j] = key;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            auto it = st.find(mat[i][j]);
            found = it != st.end();

            if (!found)
            {
                cout << no;
                return;
            }
            st.erase(it);
        }
    }

    cout << ye;
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
