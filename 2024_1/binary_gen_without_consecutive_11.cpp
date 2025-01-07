#include <iostream>
#include <string>

using namespace std;

int n;

void gen(string str)
{
    if (n == 0)
    {
        cout << str << endl;
        return;
    }

    n--;
    gen(str + '0');
    n++;

    if (str[str.length() - 1] != '1')
    {
        n--;
        gen(str + '1');
        n++;
    }
}

int main()
{
    cin >> n;

    gen("");

    return 0;
}