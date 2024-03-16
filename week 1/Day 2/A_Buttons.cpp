#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int result;

    if (a == b)
        result = a + b;
    else
        result = max(a, b) * 2 - 1;

    cout << result;

    return 0;
}