#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<string, int> mpp;

    vector<string> person1(n);
    for (int i = 0; i < n; i++)
        cin >> person1[i], mpp[person1[i]]++;

    vector<string> person2(n);
    for (int i = 0; i < n; i++)
        cin >> person2[i], mpp[person2[i]]++;

    vector<string> person3(n);
    for (int i = 0; i < n; i++)
        cin >> person3[i], mpp[person3[i]]++;

    int per1 = 0, per2 = 0, per3 = 0;
    for (string it : person1)
    {
        if (mpp[it] == 2)
            per1++;
        if (mpp[it] == 1)
            per1 += 3;
    }

    for (string it : person2)
    {
        if (mpp[it] == 2)
            per2++;
        if (mpp[it] == 1)
            per2 += 3;
    }

    for (string it : person3)
    {
        if (mpp[it] == 2)
            per3++;
        if (mpp[it] == 1)
            per3 += 3;
    }

    cout << per1 << " " << per2 << " " << per3 << '\n';
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}