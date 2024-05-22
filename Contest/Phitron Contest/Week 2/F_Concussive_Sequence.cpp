#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0 || i == arr.size() - 1)
            continue;

        int prev = arr[i - 1], curr = arr[i], next = arr[i + 1];
        if (!((prev < curr && curr > next) || (prev > curr && curr < next)))
        {
            return 0;
        }
    }

    return 1;
}

void print(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}

vector<int> rearrenge1(int arr[], int n, stack<int> st1, stack<int> st2)
{
    vector<int> rearrenged;
    if (n % 2)
        rearrenged.push_back(arr[n / 2]);

    while (!st1.empty())
    {
        rearrenged.push_back(st1.top());
        rearrenged.push_back(st2.top());
        st1.pop(), st2.pop();
    }

    return rearrenged;
}

vector<int> rearrenge2(int arr[], int n, stack<int> st1, stack<int> st2)
{
    vector<int> rearrenged;

    while (!st1.empty())
    {
        rearrenged.push_back(st2.top());
        rearrenged.push_back(st1.top());
        st1.pop(), st2.pop();
    }

    return rearrenged;
}

void solve()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    stack<int> st1, st2;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            st1.push(arr[i]);
        else
            st2.push(arr[i]);
    }

    vector<int> rearrenged = rearrenge1(arr, n, st1, st2);
    if (check(rearrenged))
    {
        print(rearrenged);
        return;
    }

    rearrenged = rearrenge2(arr, n, st1, st2);
    if (check(rearrenged))
    {
        print(rearrenged);
        return;
    }

    cout << -1;
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