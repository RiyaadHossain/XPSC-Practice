#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int ans = 0;
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] != str2[i])
            ans++;
    }

    cout << ans;

    return 0;
}