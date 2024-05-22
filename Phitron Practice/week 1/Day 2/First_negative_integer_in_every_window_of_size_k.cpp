#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(long long arr[], long long n, long long k)
{

    queue<int> qu;

    vector<long long> result;
    int i = 0, j = 0;
    while (j < n)
    {
        if (arr[j] < 0)
            qu.push(arr[j]);

        while (j - i + 1 > k)
        {
            if (arr[i] < 0)
                qu.pop();
            i++;
        }

        if (j - i + 1 == k)
        {
            if (!qu.empty())
                result.push_back(qu.front());
            else
                result.push_back(0);
        }

        j++;
    }

    return result;
}

int main()
{
    long long n, k;
    cin >> n >> k;

    long long arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<long long> result = solve(arr, n, k);
    for (int it : result)
        cout << it << " ";

    return 0;
}