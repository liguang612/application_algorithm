#include <iostream>
#include <string>

using namespace std;

string p1, p2, t;

int main()
{
    getline(cin, p1);
    getline(cin, p2);
    getline(cin, t);

    int idx;
    while ((idx = t.find(p1)) != string::npos)
    {
        t.replace(idx, p1.length(), p2);
    }

    cout << t << endl;

    return 0;
}