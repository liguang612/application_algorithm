#include <iostream>

using namespace std;

bool **mark;
short H, *h, n, W, *w;
bool count = false;

void attempt(int k);
bool check(int x, int y, bool rotate, int k);
void marked(int x, int y, bool rotate, int k, bool state);

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> H >> W >> n;
    h = new short[n];
    w = new short[n];
    mark = new bool*[H];

    for (int i = 0; i < n; i++)
    {
        cin >> h[i] >> w[i];
    }
    for (int i = 0; i < H; i++)
    {
        mark[i] = new bool[W];
        for (int j = 0; j < W; j++)
        {
            mark[i][j] = false;
        }
    }

    attempt(0);

    cout << count;

    return 0;
}

void attempt(int k) {
    if (count)
    {
        return;
    }

    int _h, _w;

    for (int b = 0; b <= 1; b++)
    {
        if (!b)
        {
            _h = h[k];
            _w = w[k];
        } else {
            _h = w[k];
            _w = h[k];
        }

        for (int i = 0; i <= H - _h; i++)
        {
            for (int j = 0; j <= W - _w; j++)
            {
                // cout << i << ' ' << j << ' ' << b << ' ' << k << endl;
                // system("pause");
                if (check(i, j, b, k))
                {
                    marked(i, j, b, k, true); // Mark where has set in
                    if (k + 1 == n)
                    {
                        count = true;
                    } else {
                        attempt(k + 1);
                    }
                    
                    // Restore
                    marked(i, j, b, k, false);
                }
            }
        }
    }
}

bool check(int x, int y, bool rotate, int k) {
    int _h, _w;

    if (!rotate)
    {
        _h = h[k];
        _w = w[k];
    } else {
        _h = w[k];
        _w = h[k];
    }

    if (x + _h > H || y + _w > W)
    {
        return false;
    }
    for (int i = x; i < x + _h; i++)
    {
        for (int j = y; j < y + _w; j++)
        {
            if (mark[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void marked(int x, int y, bool rotate, int k, bool state) {
    int _h, _w;

    if (!rotate)
    {
        _h = h[k];
        _w = w[k];
    } else {
        _h = w[k];
        _w = h[k];
    }

    for (int i = x; i < x + _h; i++)
    {
        for (int j = y; j < y + _w; j++)
        {
            mark[i][j] = state;
        }
    }
}