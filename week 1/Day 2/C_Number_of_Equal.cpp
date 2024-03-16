#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int *arr1, int *arr2, int n, int m)
{
    int left1 = 0, left2 = 0;

    vector<ll> freqCnt;

    ll ans = 0;
    while (left2 < m)
    {
        ll cnt = 0;
        while (left1 < n && arr1[left1] == arr2[left2])
            left1++, cnt++;

        if (left1 > 0 && arr2[left2] == arr2[left2 - 1])
            ans += freqCnt.back();
        else
            ans += cnt, freqCnt.push_back(cnt);

        left2++;
    }

    cout << ans;
}

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

    solve(arr1, arr2, n, m);

    return 0;
}