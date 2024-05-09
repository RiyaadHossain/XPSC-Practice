#include <bits/stdc++.h>
using namespace std;

int solve(string pat, string txt)
{
    int n = txt.size(), k = pat.size();

    map<char, int> mpp;
    for (int i = 0; i < k; i++)
        mpp[pat[i]]++;

    int ans = 0, cnt = mpp.size();
    int i = 0, j = 0;
    while (j < n)
    {
        mpp[txt[j]]--;
        if (mpp[txt[j]] == 0)
            cnt--;

        while (j - i + 1 > k)
        {
            if (mpp[txt[i]] == 0)
                cnt++;
            mpp[txt[i]]++;
            i++;
        }

        if (j - i + 1 == k && cnt == 0)
            ans++;

        j++;
    }

    return ans;
}

int main()
{
    string txt, pat;
    cin >> txt >> pat;

    cout << solve(pat, txt);

    return 0;
}