#include <iostream>

using namespace std;

int m, n;

int find_max(int *a)
{
    int max = 0;

    for (int i = 0; i < m; i++)
    {
        int j = i, k = i;
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < a[i])
            {
                break;
            }
        }
        for (k = i; k < m; k++)
        {
            if (a[k] < a[i])
            {
                break;
            }
        }

        int tmp;
        max = max < (tmp = (--k - ++j + 1) * a[i]) ? tmp : max;
    }

    return max;
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int **a, max = 0;

    cin >> n >> m;

    a = new int *[n];

    a[0] = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> a[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        a[i] = new int[m];

        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                a[i][j] += a[i - 1][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int tmp = find_max(a[i]);

        max = max < tmp ? tmp : max;
    }

    cout << max;

    return 0;
}