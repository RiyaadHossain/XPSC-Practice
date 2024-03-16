#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> result;
    int i = 4;
    while (i--)
    {
        if (n > 0)
            result.push_back(n % 10);
        else
            result.push_back(0);

        n /= 10;
    }

    reverse(result.begin(), result.end());

    for (int it : result)
        cout << it;

    return 0;
}