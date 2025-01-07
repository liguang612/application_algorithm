#include <iostream>
#include <string>

using namespace std;

int n;

void gen(string s)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    gen(s + "0");
    gen(s + "1");
}

int main()
{
    cin >> n;
    gen("");

    return 0;
}