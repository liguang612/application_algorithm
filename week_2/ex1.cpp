#include <iostream>

using namespace std;

int main() {
    int *a, m, n, **res;

    cin >> n >> m;
    a = new int[n];
    res = new int*[n + 1];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        res[i] = new int[m + 1];
    }
    res[n] = new int[m + 1];

    res[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        res[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        res[i][0] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            res[i][j] = res[i - 1][j - a[i - 1]] + res[i][j - a[i - 1]];
        }
    }

    cout << res[n][m];

    return 0;
}