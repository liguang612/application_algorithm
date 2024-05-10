#include <iostream>
#include <algorithm>

using namespace std;

int a[1001], t[1001], N, T, D, res = -1;
int cost[10001][101];

int main()
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T >> D;

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> t[i];
    }

    for (int i = 1; i <= N; i++)
    {
        int _t = t[i], lwr = max(0, i - D);

        for (int j = 1; j <= T; j++)
        {
            for (int k = lwr; k < i; k++)
            {
                if (j >= _t)
                {
                    cost[i][j] = max(cost[k][j - _t] + a[i], cost[i][j]);
                }
            }

            res = max(cost[i][j], res);
        }
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     for (int j = 0; j <= T; j++)
    //     {
    //         cout << cost[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    cout << res;

    return 0;
}