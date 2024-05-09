#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        st.insert(num);
    }

    int duplicates = n - st.size();
    int result = n - (duplicates + (duplicates % 2));
    cout << result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }
    return 0;
}