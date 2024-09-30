#include <iostream>
#include <algorithm>

using namespace std;

bool visited[13];
int best = INT16_MAX, c[13][13], cmin = INT16_MAX, d[13], f = 0, K, load[6], n, nbR, Q, segments, x[13], y[6];

bool checkX(int v, int k) {
    if (v > 0 && visited[v])
    {
        return false;
    }
    if (load[k] + d[v] > Q)
    {
        return false;
    }
    return true;
}

void tryX(int s, int k) {
    if (!s)
    {
        if (k < K)
        {
            tryX(y[k + 1], k + 1);
        }
        return;
    }
    for (int v = 0; v <= n; v++)
    {
        if (checkX(v, k))
        {
            x[s] = v;
            visited[v] = true;
            f += c[s][v];
            load[k] += d[v];
            ++segments;

            if (v > 0)
            {
                if (f + (n + nbR - segments) * cmin < best)
                {
                    tryX(v, k);
                } 
            } else {
                if (k == K)
                {
                    if (segments == n + nbR)
                    {
                        best = min(best, f);
                    } 
                } else {
                    if (f + (n + nbR - segments) * cmin < best)
                    {
                        tryX(y[k + 1], k + 1);
                    }
                }
            }
            visited[v] = false;
            f -= c[s][v];
            load[k] -= d[v];
            --segments;
        }
    }
}

bool checkY(int v, int k) {
    if (!v)
    {
        return true;
    }
    if (load[k] + d[v] > Q)
    {
        return false;
    }
    if (visited[v])
    {
        return false;
    }
    return true;
}

void tryY(int k) {
    int s = 0;

    if (y[k - 1] > 0)
    {
        s = y[k - 1] + 1;
    }
    
    for (int v = s; v <= n; v++)
    {
        if (checkY(v, k))
        {
            y[k] = v;

            if (v)
            {
                ++segments;
                visited[v] = true;
                f += c[0][v];
                load[k] += d[v];
            }

            if (k < K)
            {
                tryY(k + 1);
            } else {
                nbR = segments;
                tryX(y[1], 1);
            }

            if (v)
            {
                --segments;
                load[k] -= d[v];
                visited[v] = false;
                f -= c[0][v];
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> K >> Q;

    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cin >> c[i][j];
            if (i != j) cmin = min(c[i][j], cmin);
        }
    }    

    y[0] = 0;

    tryY(1);

    cout << best;

    return 0;
}