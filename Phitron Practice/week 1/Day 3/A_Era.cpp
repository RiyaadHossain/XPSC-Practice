#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> numbers(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> numbers[i];

    int operations = 0;
    for (int i = 1; i <= n; i++)
    {
        if (numbers[i] > i)
            operations = max(operations, numbers[i] - i);
    }

    cout << operations << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}