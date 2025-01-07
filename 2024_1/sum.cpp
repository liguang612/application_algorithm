#include <iostream>

using namespace std;

int main()
{
    int n, a, s = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        s += a;
    }

    cout << s;

    return 0;
}