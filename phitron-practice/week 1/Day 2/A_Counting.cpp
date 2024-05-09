#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int result = b - a + 1;

    cout << (result < 0 ? 0 : result);

    return 0;
}