#include <iostream>

using namespace std;

int main() {
    int n, m, a[200][200], sum;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

// horizontal
    for (int i = 0; i < n - 1; i++)
    {
        sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += a[i][j];
        }
        cout << sum << ' ';
    }
    sum = 0;
    for (int j = 0; j < m; j++)
    {
        sum += a[n - 1][j];
    }
    cout << sum << endl;

// vertical
    for (int j = 0; j < m - 1; j++)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += a[i][j];
        }
        cout << sum << ' ';
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i][m - 1];
    }
    cout << sum;
    
    return 0;
}