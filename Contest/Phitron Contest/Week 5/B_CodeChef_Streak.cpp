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

void solve()
{
    int n;
    cin >> n;

    int arr1[n], arr2[n];
    int om = 0, addy = 0, omM = 0, addyM = 0;
    for (int i = 0; i < n; i++)
        cin >> arr1[i], om = (arr1[i] > 0 ? om + 1 : 0), omM = max(omM, om);
    for (int i = 0; i < n; i++)
        cin >> arr2[i], addy = (arr2[i] > 0 ? addy + 1 : 0), addyM = max(addyM, addy);

    if (omM == addyM)
        cout << "Draw";
    else if (omM > addyM)
        cout << "Om";
    else
        cout << "Addy";
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
