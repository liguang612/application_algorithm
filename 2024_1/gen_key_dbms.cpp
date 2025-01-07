#include <iostream>
#include <set>
#include <string>

using namespace std;

int l, m, n;
set<string> keys;

string increase(string s)
{
    s[l - 1]++;
    for (int i = l - 1; i >= 0; i--)
    {
        if (s[i] > '9')
        {
            s[i] = '0';
            s[i - 1]++;
        }
        else
        {
            break;
        }
    }

    return s;
}

int main()
{
    cin >> n >> l >> m;

    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        keys.insert(s);
    }

    s = "";
    for (int i = 0; i < l; i++)
        s += '0';

    while (m)
    {
        s = increase(s);
        cout << s << endl;

        if (!keys.erase(s))
        {
            m--;
        }
    }
    for (string s : keys)
    {
        cout << s << endl;
    }

    return 0;
}