#include <bits/stdc++.h>
using namespace std;

#define ye "YES"
#define no "NO"
#define int long long

int32_t main()
{
   int n,m;
   cin >> n >> m;

   int x, y;
   cin >> x >> y;

   int result = (n * x) + (m * y);
   cout << result;

   return 0;
}