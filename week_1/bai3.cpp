#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, m, n, **rmq, sum = 0;

    cin >> n;

    rmq = new int*[n];
    rmq[0] = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> rmq[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        int _i = n - i;

        rmq[i] = new int[_i];
        for (int j = 0; j < _i; j++)
        {
            rmq[i][j] = min(rmq[i - 1][j], rmq[0][j + i]);
        }
    }
    
    cin >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        sum += rmq[b - a][a];
    }
    
    cout << sum;
    
    return 0;
}