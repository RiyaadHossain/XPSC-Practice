#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
    string s;
    cin >> s;

    int n = s.size();

    vector<int> freq(26);
    for (int i = 0; i < n; i++)
        freq[s[i] - 'A']++;

    char ch;
    int odd = 0;
    for (int i = 0; i < 26; i++)
    {
        odd += (freq[i] % 2);
        if (odd)
            ch = 'A' + i;
    }

    if ((n % 2 && odd > 1) || (n % 2 == 0 && odd))
    {
        cout << "NO SOLUTION";
        return 0;
    }

    vector<int> ans(n);
    int left = 0, right = n - 1;

    if (n % 2)
        ans[n / 2] = ch, freq[ch - 'A']--;

    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {
            freq[i] -= 2;
            ans[left] = char('A' + i);
            ans[right] = char('A' + i);
            left++, right--;
        }
    }

    for (char ch : ans)
        cout << ch;

    return 0;
}