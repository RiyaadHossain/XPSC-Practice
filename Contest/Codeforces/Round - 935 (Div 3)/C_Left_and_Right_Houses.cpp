#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> prefix;
bool isRoad(int i)
{
    int leftOnes = prefix[i];
    int leftZeros = i + 1 - leftOnes;

    int rightOnes = prefix[n - 1] - leftOnes;
    int rightZeros = n - 1 - i - rightOnes;

    if (leftZeros >= leftOnes && rightOnes >= rightZeros)
        return 1;
    return 0;
}

void solve()
{
    cin >> n;

    char houses[n];
    for (int i = 0; i < n; i++)
        cin >> houses[i];

    prefix.resize(n, 0);
    prefix[0] = houses[0] == '1';
    for (int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + (houses[i] == '1');

    int ans = -1;

    // Handle Edge Case (ans == 0) outside loop
    if (prefix[n - 1] >= (n + 1) / 2)
        ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (isRoad(i))
        {
            if (abs(n - 2 * (i + 1)) < abs(n - 2 * ans)) // n- (2*(i+1)) for handling edge cases
                ans = i + 1;
        }
    }

    cout << (ans != -1 ? ans : 0);
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