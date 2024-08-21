#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of all the even elements in a range.

const int N = 2e5 * 4;
vector<int> a(N);
vector<int> t(N,1e9);

void build(int node, int L, int R)
{
    if (L == R)
    {
        t[node] = a[L];
        return;
    }

    int mid = (L + R) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    build(left, L, mid);
    build(right, mid + 1, R);
    t[node] = min(t[left], t[right]);
}

void update(int node, int L, int R, int pos, int val)
{
    if (pos < L || pos > R)
        return;
    if (L == R)
    {
        t[node] = val;
        return;
    }

    int mid = (L + R) / 2;
    int left = node * 2;
    int right = node * 2 + 1;

    update(left, L, mid, pos, val);
    update(right, mid + 1, R, pos, val);
    t[node] = min(t[left], t[right]);
}

int query(int node, int L, int R, int l, int r)
{
    if (l > R || r < L)
        return 1e9;
    if (l <= L && r >= R)
        return t[node];

    int mid = (L + R) / 2;
    int x = query(node * 2, L, mid, l, r);
    int y = query(node * 2 + 1, mid+1, R, l, r);
    return min(x,y);
}

int main()
{

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    build(1, 1, n);

    int q;
    cin >> q;

    int sign, l, r, pos, val;
    while (q--)
    {
        cin >> sign;

        if (sign == 1)
        {
            cin >> pos >> val;
            update(1, 1, n, pos, val);
        }
        else
        {
            cin >> l >> r;
            int x = query(1, 1, n, l, r);
            cout << x << endl;
        }
    }

    return 0;
}