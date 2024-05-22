#include <bits/stdc++.h>
using namespace std;

int n;
bool skip(string &str, int i)
{
    if (str[i] == str[i + 1] && str[i] == str[i + 2])
        return 1;

    if (i < n - 3 && str[i] == str[i + 1] && str[i] == str[i + 3])
        return 1;

    return 0;
}

void solve()
{
    cin >> n;

    string str;
    cin >> str;

    vector<string> strings;
    strings.push_back(str);

    int ans = 0, addOne = 0;
    for (int i = 0; i < n - 2; i++)
    {
        if (str[i] == str[i + 1] && str[i] == str[i + 2])
            addOne = 1;
        if (!skip(str, i))
            ans++;
    }

    cout << ans + addOne;
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