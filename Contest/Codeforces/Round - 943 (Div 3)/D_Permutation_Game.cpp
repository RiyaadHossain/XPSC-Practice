#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ye "YES"
#define no "NO"
#define int long long

// Data Type
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> getPath(int turns, int &n, int &start, vector<int> &permutation)
{
    int idx = start;
    vector<int> path;
    vector<int> vis(n + 1, 0);
    while (turns--)
    {
        if (vis[idx])
            break;
        path.push_back(idx);
        vis[idx] = 1;
        idx = permutation[idx];
    }

    return path;
}

void solve()
{
    int n, k, pb, ps;
    cin >> n >> k >> pb >> ps;

    vector<int> permuation(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> permuation[i];

    vector<int> score(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> score[i];

    vector<int> pathB = getPath(k, n, pb, permuation);
    vector<int> pathS = getPath(k, n, ps, permuation);

    auto getScore = [&](vector<int> &path)
    {
        int preSum = 0, mxScore = 0;
        for (int i = 0; i < path.size(); i++)
        {
            if (i + 1 > k)
                break;
            int currS = preSum + (k - i) * score[path[i]];
            mxScore = max(mxScore, currS);
            preSum += score[path[i]];
        }

        return mxScore;
    };

    int scoreB = getScore(pathB);
    int scoreS = getScore(pathS);

    if (scoreB > scoreS)
        cout << "Bodya";
    else if (scoreB < scoreS)
        cout << "Sasha";
    else
        cout << "Draw";
}

int32_t main()
{
    fastio;

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}
