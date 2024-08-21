#include <bits/stdc++.h>
using namespace std;

// Problem: Sum of all the even elements in a range.

class SegmentTree
{
    int n;
    vector<int> a;
    vector<int> t;

public:
    SegmentTree(int n)
    {
        this->n = n;
        a.resize(n * 4);
        t.resize(n * 4);
    }

    void input()
    {
        for (int i = 1; i <= n; i++)
            cin >> a[i];
    }

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
        t[node] = t[left] + t[right];
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
        t[node] = t[left] + t[right];
    }

    int query(int node, int L, int R, int l, int r)
    {
        if (l > R || r < L)
            return 0;
        if (l <= L && r >= R)
            return t[node];

        int mid = (L + R) / 2;
        int x = query(node * 2, L, mid, l, r);
        int y = query(node * 2 + 1, mid + 1, R, l, r);
        return x + y;
    }
};

int main()
{

    int n;
    cin >> n;

    SegmentTree segTree = SegmentTree(n);
    segTree.input();
    segTree.build(1, 1, n);

    int q;
    cin >> q;

    int sign, l, r, pos, val;
    while (q--)
    {
        cin >> sign;

        if (sign == 1)
        {
            cin >> pos >> val;
            segTree.update(1, 1, n, pos, val);
        }
        else
        {
            cin >> l >> r;
            int x = segTree.query(1, 1, n, l, r);
            cout << x << endl;
        }
    }

    return 0;
}