#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int arr1[n];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int arr2[m];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<int> result;
    int left1 = 0, left2 = 0;
    while (left2 < m)
    {
        while (left1 < n && arr1[left1] < arr2[left2])
            left1++;

        result.push_back(left1);
        left2++;
    }

    for (int it : result)
        cout << it << " ";

    return 0;
}