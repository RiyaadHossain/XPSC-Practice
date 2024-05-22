#include <bits/stdc++.h>

#define ll long long

#define forn(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

#define pb push_back
#define sz(a) (int)a.size()

using namespace std;

void solve()
{
    int n, s;
    cin >> n >> s;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int i = 0, j = 0, ans = INT_MAX;
    int sum = 0;
    while (j < n)
    {
        sum += arr[j];

        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == s)
            ans = min(ans, n - (j - i + 1));

        j++;
    }

    cout << (ans != INT_MAX ? ans : -1);
}

ll query(int l, int r, vector<ll> &p)
{
    return p[r] - (l ? p[l - 1] : 0);
}

void solve2()
{
    int n, s;
    cin >> n >> s;
    vector<ll> a(n), p(n);
    forn(i, n)
    {
        cin >> a[i];
        p[i] = a[i];
        if (i)
            p[i] += p[i - 1];
    }

    int ans = INT_MAX;

    for (int i = 0; i < n; ++i)
    {
        int l = i, r = n - 1, pos = -1;
        while (l <= r)
        {
            int mid = l + r >> 1;
            if (query(i, mid, p) <= s)
            {
                pos = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (query(i, pos, p) != s)
            continue;
        ans = min(ans, n - (pos - i + 1));
    }

    cout << (ans == INT_MAX ? -1 : ans);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve2();
        cout << endl;
    }

    return 0;
}