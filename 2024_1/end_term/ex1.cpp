#include <iostream>

using namespace std;

int n, x, y, cnt = 0;

int main()
{
    cin >> n >> x >> y;

    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (a >= x && a <= y)
        {
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}