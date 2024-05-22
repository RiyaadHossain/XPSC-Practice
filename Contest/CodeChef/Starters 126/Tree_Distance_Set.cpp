#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> graph[2001];
vector<int> diameter;
void inputTree()
{
    cin >> n;
    int e = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[i].size())
            graph[i].clear();
    }

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int getLeaf(int src)
{
    int dis[n] = {-1}, vis[n] = {0};

    queue<int> qu;
    qu.push(src);
    dis[src] = 0;
    vis[src] = 1;

    while (!qu.empty())
    {
        int u = qu.front();
        qu.pop();

        for (int v : graph[u])
        {
            if (vis[v] != 1)
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                qu.push(v);
            }
        }
    }

    int leaf = src;
    for (int i = 0; i < n; i++)
        if (dis[leaf] < dis[i])
            leaf = i;

    return leaf;
}

bool found = 0;
void getDiameter(int src, int des, int par)
{
    if (found)
        return;

    diameter.push_back(src);

    if (src == des)
        found = 1;

    for (int v : graph[src])
    {
        if (v != par)
            getDiameter(v, des, src);
    }

    if (!found)
        diameter.pop_back();
}

void solve()
{
    // 0. Take I/O
    inputTree();
    found = 0, diameter.clear();

    // 1. Get Diameter of the Tree
    int leaf1 = getLeaf(0);
    int leaf2 = getLeaf(leaf1);
    getDiameter(leaf1, leaf2, -1);

    // 2. Color Half of the Diameter with Red and rest Blue
    int coloring[n];
    int vis[n] = {0};

    int blueCnt = 0, redCnt = 0;
    for (int i = 0; i < diameter.size(); i++)
    {
        int node = diameter[i];
        if (i < diameter.size() / 2)
            coloring[node] = 1, redCnt++;
        else
            coloring[node] = 0, blueCnt++;

        vis[node] = 1;
    }

    // 3. Color Remaing nodes (half of them are Blue and rest Red)
    vector<int> remainging;
    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            remainging.push_back(i);

    for (int i = 0; i < remainging.size(); i++)
    {
        int node = remainging[i];
        coloring[node] = redCnt <= blueCnt ? 1 : 0;
        coloring[node] == 1 ? redCnt++ : blueCnt++;
    }

    // 4. Pring Color
    for (int i = 0; i < n; i++)
    {
        if (coloring[i])
            cout << 'R';
        else
            cout << 'B';
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}