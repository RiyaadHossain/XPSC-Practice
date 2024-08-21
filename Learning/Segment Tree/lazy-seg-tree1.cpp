#include <bits/stdc++.h>
using namespace std;

// Lazy Segment Tree w/o propagation: Range Update + Signle Query
/*
    Problem Statement:
    An array a is given and you have to perform q queries.
    if (The first char of the query is 1)
        update the range between l and r by adding u
    else
        output is the pos an odd or even number
*/

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
    }

    void update(int node, int L, int R, int l, int r, int val)
    {
        if (l > R || r < L)
            return;
        if (l <= L && r >= R)
        {
            t[node] += val;
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        update(left, L, mid, l, r, val);
        update(right, mid + 1, R, l, r, val);
    }

    int query(int node, int L, int R, int pos)
    {
        if (pos > R || pos < L)
            return 0;
        if (L == R)
            return t[node];

        int mid = (L + R) / 2;
        int x = query(node * 2, L, mid, pos);
        int y = query(node * 2 + 1, mid + 1, R, pos);
        return x + y + t[node];
    }
};

int32_t main()
{

    int n;
    cin >> n;

    SegmentTree segTree = SegmentTree(n);
    segTree.input();
    segTree.build(1, 1, n);

    int q;
    cin >> q;

    int sign, l, r, pos, u;
    while (q--)
    {
        cin >> sign;
        if (sign==1)
        {
            cin >> l >> r >> u;
            segTree.update(1, 1, n, l, r, u);
        }
        else
        {
            cin >> pos;
            int x = segTree.query(1, 1, n, pos);
            x % 2 ? cout << "Odd" << endl : cout << "Even" << endl;
        }
    }

    return 0;
}