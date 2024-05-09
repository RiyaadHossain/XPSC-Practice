#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
        cin >> words[i];

    int ans = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        string word1 = words[i];
        for (int j = i + 1; j < n; j++)
        {
            string word2 = words[j];
            int diff = 0;
            for (int k = 0; k < m; k++)
            {
                diff += abs(word1[k] - word2[k]);
            }

            ans = min(ans, diff);
        }
    }

    cout << ans;
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