#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int alphabet[26] = {0};
    for (int i = 0; i < str.size(); i++)
        alphabet[str[i] - 'a']++;

    bool found = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 0)
        {
            found = 1;
            cout << char('a' + i);
            break;
        }
    }

    if (!found)
        cout << "None";

    return 0;
}