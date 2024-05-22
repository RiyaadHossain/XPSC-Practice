#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    int n, m;
    cin >> n >> m;

    int x;
    multiset<int> st;
    for (int i = 0; i < n; i++)
        cin >> x, st.insert(x);

    while (m--)
    {
        cin >> x;
        auto it = st.upper_bound(x);
        if (it == st.begin())
        {
            cout << -1 << endl;
            continue;
        }

        it--;
        cout << *it << endl;
        st.erase(it);
    }

    return 0;
}