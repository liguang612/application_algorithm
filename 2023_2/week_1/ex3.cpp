#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int c, **rmq;

void gen(int n)
{
    int tmp = 1, s_tmp = 1;

    for (int i = 1; i < c; i++)
    {
        int _tmp = n - s_tmp;
        for (int j = 0; j < _tmp; j++)
        {
            rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][j + tmp]);
        }

        tmp *= 2;
        s_tmp += tmp;
    }
}

void display(int n)
{
    int tmp = 1, s_tmp = 0;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < n - s_tmp; j++)
        {
            cout << rmq[i][j] << ' ';
        }
        cout << endl;

        s_tmp += tmp;
        tmp *= 2;
    }
}

int read()
{
    char c;
    int tmp = 0;

    while (c = getchar())
    {
        if (c == ' ' || c == (char)10 || feof(stdin))
        {
            return tmp;
        }
        tmp = tmp * 10 + c - 48;
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);

    int a, b, m, n, sum = 0, tmp = 1, s_tmp = 1;

    cin >> n;

    c = (int)log2(n) + 1;

    rmq = new int *[c];

    rmq[0] = new int[n];
    read();
    for (int i = 0; i < n; i++)
    {
        rmq[0][i] = read();
    }

    for (int i = 1; i < c; i++)
    {
        rmq[i] = new int[n - s_tmp];

        tmp *= 2;
        s_tmp += tmp;
    }
    gen(n);
    // display(n);

    cin >> m;

    read();
    for (int i = 0; i < m; i++)
    {
        a = read();
        b = read();

        int tmp = (int)log2(b - a + 1);

        sum += min(rmq[tmp][a], rmq[tmp][b - (int)pow(2, tmp) + 1]);
    }

    cout << sum;

    return 0;
}