#include <bits/stdc++.h>
using namespace std;

// Lazy Segment Tree with propagation: Range Update + Range Query

/*
    Problem Statement:
    Given an array a and perform q quries.
    if (the first character of the query is 1)
        update the range l and r by adding u
    else
        output the maximum number of range l and r
*/

class SegmentTree
{
public:
    int n;
    vector<int> a;
    vector<int> t;
    vector<int> high;

    SegmentTree(int n)
    {
        this->n = n;
        a.resize(n * 4);
        t.resize(n * 4);
        high.resize(n * 4);
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
            high[node] = a[L];
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        build(left, L, mid);
        build(right, mid + 1, R);
        high[node] = max(high[left], high[right]);
    }

    void propagate(int node, int L, int R)
    {
        int left = node * 2, right = node * 2 + 1;

        int val = t[node];
        t[node] = 0;
        t[left] += val;
        t[right] += val;

        high[left] += val;
        high[right] += val;
    }

    void update(int node, int L, int R, int l, int r, int val)
    {
        if (r < L || l > R)
            return;
        if (l <= L && r >= R)
        {
            t[node] += val;
            high[node] += val;
            return;
        }

        int mid = (L + R) / 2;
        int left = node * 2;
        int right = node * 2 + 1;

        if (t[node] > 0)
            propagate(node, L, R);

        update(left, L, mid, l, r, val);
        update(right, mid + 1, R, l, r, val);
        high[node] = max(high[left], high[right]);
    }

    int query(int node, int L, int R, int l, int r)
    {
        if (l > R || r < L)
            return 0;
        if (l <= L && r >= R)
            return high[node];

        if (t[node] > 0)
            propagate(node, L, R);

        int mid = (L + R) / 2;
        int x = query(node * 2, L, mid, l, r);
        int y = query(node * 2 + 1, mid + 1, R, l, r);
        return max(x, y);
    }
};

void print(vector<int> vec, int n)
{
    for (int i = 1; i <= n; i++)
        cout << vec[i] << " ";

    cout << endl;
}

int32_t main()
{

    int n;
    cin >> n;

    SegmentTree segTree = SegmentTree(n);
    segTree.input();
    segTree.build(1, 1, n);

    int q;
    cin >> q;

    int sign, l, r, val;
    while (q--)
    {
        cin >> sign;
        if (sign == 1)
        {
            cin >> l >> r >> val;
            segTree.update(1, 1, n, l, r, val);
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
