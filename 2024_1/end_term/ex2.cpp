#include <iostream>

using namespace std;

int n, x, y, m, ps[100001] = {0};

int main()
{

    cin >> n >> x >> y;

    int a, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        ps[i] = ps[i - 1] + a;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        int res = ps[b] - ps[a - 1];
        if (res >= x && res <= y)
        {
            cout << 1;
        }
        else
            cout << 0;

        cout << endl;
    }

    return 0;
}