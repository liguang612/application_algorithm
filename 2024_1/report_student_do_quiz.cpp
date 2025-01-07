#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> cnt;

int main()
{
    string s;

    cin >> s;
    while (s != "*")
    {
        cnt[s]++;
        cin >> s >> s >> s >> s;
    }

    for (auto &&i : cnt)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}