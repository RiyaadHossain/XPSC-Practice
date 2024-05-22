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

int maxFriend(int n, priority_queue<pii> a, priority_queue<pii> b, priority_queue<pii> c)
{
    bool day[n] = {0};

    int total = a.top().first;
    day[a.top().second] = 1;

    if (day[b.top().second])
        b.pop();
    total += b.top().first;
    day[b.top().second] = 1;

    if (day[c.top().second])
        c.pop();
    if (day[c.top().second])
        c.pop();

    total += c.top().first;
    day[c.top().second] = 1;

    return total;
}

void solve()
{
    int n;
    cin >> n;

    int num;
    priority_queue<pii> ski;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ski.push({num, i});
    }

    priority_queue<pii> movie;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        movie.push({num, i});
    }

    priority_queue<pii> game;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        game.push({num, i});
    }

    int ans = 0;
    ans = max(ans, maxFriend(n, ski, movie, game));
    ans = max(ans, maxFriend(n, ski, game, movie));
    ans = max(ans, maxFriend(n, game, ski, movie));
    ans = max(ans, maxFriend(n, game, movie, ski));
    ans = max(ans, maxFriend(n, ski, movie, game));
    ans = max(ans, maxFriend(n, ski, game, movie));

    cout << ans;
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
