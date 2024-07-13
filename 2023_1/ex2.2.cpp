#include <iostream>
#include <algorithm>

using namespace std;

int F[101][101][101], H[50], W[50], L[50], h, w, l, n, T, rec;

void reset() {
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            for (int k = 0; k < 101; k++)
                F[i][j][k] = i * j * k;

    rec = 100000;
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> T;
    while (T--)
    {
        cin >> l >> w >> h >> n;

        reset();

        for (int i = 0; i < n; i++)
        {
            cin >> L[i] >> W[i] >> H[i];
            for (int x = 1; x <= l; x++)
                for (int y = 1; y <= w; y++)
                    for (int z = 1; z <= h; z++)
                        if (x >= L[i] && y >= W[i] && z >= H[i]) {
                            int res = F[x][y][z];
                            res = min(res, F[x - L[i]][y][z] + F[L[i]][y - W[i]][z] + F[L[i]][W[i]][z - H[i]]);
                            res = min(res, F[x - L[i]][y][z] + F[L[i]][y][z - H[i]] + F[L[i]][y - W[i]][H[i]]);
                            res = min(res, F[x][y - W[i]][z] + F[x - L[i]][W[i]][z] + F[L[i]][W[i]][z - H[i]]);
                            res = min(res, F[x][y - W[i]][z] + F[x][W[i]][z - H[i]] + F[x - L[i]][W[i]][H[i]]);
                            res = min(res, F[x][y][z - H[i]] + F[x - L[i]][y][H[i]] + F[L[i]][y - W[i]][H[i]]);
                            res = min(res, F[x][y][z - H[i]] + F[x][y - W[i]][H[i]] + F[x - L[i]][W[i]][H[i]]);

                            F[x][y][z] = res;
                        }
        }

        cout << F[l][w][h] << endl;

    }
    return 0;
}