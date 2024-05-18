#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long
typedef pair<int, int> pii;

int32_t main()
{
    int n, x;
    cin >> n >> x;

    vector<int> curr(n), arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i], curr[i] = arr[i];

    sort(curr.begin(), curr.end());

    int it1 = -1, it2 = -1, it3 = -1;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            int tar = curr[i] + curr[j];
            if (tar >= x)
                break;

            if (binary_search(curr.begin() + j + 1, curr.end(), x - tar))
            {
                it1 = curr[i], it2 = curr[j], it3 = x - tar;
                break;
            }
        }
    }

    if (it1 == -1)
    {
        cout << "IMPOSSIBLE";
        return 0;
    }

    int t1 = 0, t2 = 0, t3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (!t1 && arr[i] == it1)
            it1 = i + 1, t1 = 1;
        else if (!t2 && arr[i] == it2)
            it2 = i + 1, t2 = 1;
        else if (!t3 && arr[i] == it3)
            it3 = i + 1, t3 = 1;
    }

    cout << it1 << " " << it2 << " " << it3 << endl;

    return 0;
}