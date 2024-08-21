#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// Utilities
#define endl '\n'
#define int long long
#define no cout << "NO"
#define ye cout << "YES"
#define print(...) cout << (__VA_ARGS__)
#define printsp(...) cout << (__VA_ARGS__) << ' '
#define println(...) cout << (__VA_ARGS__) << '\n'

// Looping Mechanism
#define forEach(x, ds) for (auto &x : ds)
#define forr(i, a, b) for (int i = (a); i <= (b); ++i)
#define rforr(i, a, b) for (int i = (a); i >= (b); --i)

// Shortcut Functions
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define countSetBit(x) __builtin_popcountll(x)
#define dsFind(x, ds) (ds.find(x) != ds.end())

// Data Types
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef map<int, int> mi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

// Constant Varialbes
const int inf = 1e9;
const int llinf = 1e18;
const int mod = 1e9 + 7;

vector<string> generateSubseq(string str, int k)
{
    int n = sz(str);
    vector<bool> v(n);
    fill(v.begin(), v.begin() + k, true);

    vector<string> result;
    do
    {
        string subsequence;
        for (int i = 0; i < n; ++i)
            if (v[i])
                subsequence.push_back(str[i]);
        result.pb(subsequence);
    } while (prev_permutation(v.begin(), v.end()));

    return result;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    map<char, int> freq;
    forr(i, 0, n - 1)
        freq[a[i]]++;

    string s;
    for (auto [x, y] : freq)
        s.pb(x);

    auto contain = [&](char ch, string str) -> bool
    {
        forr(i, 0, sz(str) - 1) if (ch == str[i]) return 1;
        return 0;
    };

    auto mxSubstr = [&](string &s1, string &s2) -> int
    {
        int res = 0, cnt = 0;
        forr(i, 0, n - 1)
        {
            if (s1[i] == s2[i])
                cnt++;

            if (s1[i] != s2[i] || i == n - 1)
                res += ((cnt * (cnt + 1)) / 2), cnt = 0;
        }

        return res;
    };

    int ans = 0;
    vector<string> allSubSeq = generateSubseq(s, k);
    forr(i, 0, sz(allSubSeq) - 1)
    {
        string tmp = a;
        forr(j, 0, n - 1) if (contain(a[j], allSubSeq[i]))
            tmp[j] = b[j];
        ans = max(mxSubstr(tmp, b), ans);
    }

    print(ans);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}