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

vector<int> cubes;
void generateCubes()
{
    for (int i = 1; pow(i, 3) < 1e12; i++)
        cubes.push_back(pow(i, 3));
};

void solve()
{
    int x;
    cin >> x;

    auto search = [&](int key)
    {
        int left, right, mid;
        left = 0, right = cubes.size() - 1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (cubes[mid] == key)
                return 1;

            if (cubes[mid] > key)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return 0;
    };

    bool ans = 0;
    for (int i = 0; i < cubes.size(); i++)
    {
        if (search(x - cubes[i]))
        {
            cout << ye;
            return;
        }
    }

    cout << no;
}

int32_t main()
{
    fastio;
    generateCubes();

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
