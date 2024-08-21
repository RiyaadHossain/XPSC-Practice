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
typedef set<int> st;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;
typedef multiset<int> ms;
typedef map<int, int> mi;
typedef map<char, int> mc;
typedef pair<int, int> pi;
typedef priority_queue<int> max_heap;
typedef priority_queue<int, vi, greater<int>()> min_heap;

// Constant Varialbes
const int mod = 1e9 + 7;
const int inf = 1e9;
const int llinf = 1e18;

class Node
{
public:
    int val, code;
    Node *left, *right, *par;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
        this->par = NULL;
    }
};

class CMP
{
public:
    bool operator()(Node a, Node b)
    {
        return a.val < b.val;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<pair<char, int>> freq(n);
    forr(i, 0, n - 1)
    {
        cin >> freq[i].ff;
        cin >> freq[i].ss;
    }

    map<char, Node> track_node;
    priority_queue<Node, vector<Node>, CMP> nodes;
    for (auto [ch, freqq] : freq)
    {
        Node *newNode = new Node(freqq);
        nodes.push(newNode);
        track_node[ch] = newNode;
    }

    while (sz(nodes) > 1)
    {
        Node *left_node = nodes.top();
        nodes.pop();
        Node *right_node = nodes.top();
        nodes.pop();

        int val = left_node->val + right_node->val;
        Node *newNode = new Node(val);
        newNode->left = left_node, newNode->right = right_node;
        left_node->par = right_node->par = newNode;
        left_node->code = 0, right_node->code = 1;

        nodes.push(newNode);
    }

    map<char, string> node_code;
    for (auto [ch, node] : track_node)
    {
        stack<int> code;
        while (node.par != NULL)
        {
            code.push(node.code);
            node = node.par;
        }
        node_code[ch] = string(all(code));
    }

    Node *root = nodes.top();
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