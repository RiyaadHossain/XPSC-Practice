#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string str;
    cin >> str;

    stack<int> st;
    int operationNeed = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
            st.push(str[i]);
        else if (st.empty())
            operationNeed++;
        else
            st.pop();
    }

    operationNeed += st.size();

    cout << operationNeed / 2;
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