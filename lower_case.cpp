#include <iostream>
#include <string>

using namespace std;

string lowerCase(string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    return s;
}

int main()
{
    string s;

    cin >> s;
    cout << lowerCase(s) << endl;

    return 0;
}