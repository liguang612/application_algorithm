#include <iostream>
#include <queue>

using namespace std;

struct coord {
    int x;
    int y;

    coord(int x, int y) : x(x), y(y) {}
};

int main() {
    int c, m, **maze, n, r;
    queue<coord> q;

    cin >> n >> m >> r >> c;
    --c;
    --r;

    maze = new int*[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> maze[i][j];
            maze[i][j] = -maze[i][j]; // Brick will be -1
        }
    }
    
    q.push(coord(r, c));
    while (!q.empty())
    {
        coord c = q.front();
        int cur = maze[c.x][c.y] + 1;

        if (c.x == 0 || c.x == n - 1 || c.y == 0 || c.y == m - 1)
        {
            cout << cur;
            return 0;
        }

        if (maze[c.x - 1][c.y] == 0)
        {
            maze[c.x - 1][c.y] = cur;
            q.push(coord(c.x - 1, c.y));
        }
        if (maze[c.x + 1][c.y] == 0)
        {
            maze[c.x + 1][c.y] = cur;
            q.push(coord(c.x + 1, c.y));
        }
        if (maze[c.x][c.y - 1] == 0)
        {
            maze[c.x][c.y - 1] = cur;
            q.push(coord(c.x, c.y - 1));
        }
        if (maze[c.x][c.y + 1] == 0)
        {
            maze[c.x][c.y + 1] = cur;
            q.push(coord(c.x, c.y + 1));
        }

        q.pop();
    }
    cout << -1;

    return 0;
}