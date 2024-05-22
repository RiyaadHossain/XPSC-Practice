#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

/*
    Lower Bound:
        exist -> first occurance
        not exist -> first greater than target
        all values are less than target -> extra value than last element
*/

/*
    Upper Bound:
        exist/not exist -> first greater than target
        target is largest or above -> extra value than last element
*/

int32_t main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int q;
    cin >> q;
    while (q--)
    {
        int t;
        cin >> t;

        auto it = upper_bound(arr, arr + n, t) - arr;
        cout << it << endl;
    }

    return 0;
}