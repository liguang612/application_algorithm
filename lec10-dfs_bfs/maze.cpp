#include <iostream>
#include <queue>

using namespace std;

int R, C, r, c, maze[1000][1000];
queue<pair<int, pair<int, int>>> q;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> R >> C >> r >> c;
  r--; c--;

  for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
      cin >> maze[i][j];

  q.push({ 1,{r,c} });
  while (!q.empty())
  {
    auto it = q.front();
    q.pop();

    r = it.second.first; c = it.second.second;

    if (r == 0 || r == R - 1)
    {
      cout << it.first;
      return 0;
    }
    if (c == 0 || c == C - 1)
    {
      cout << it.first;
      return 0;
    }

    if (c > 0 && !maze[r][c - 1]) q.push({ it.first + 1, {r,c - 1} });
    if (c < C - 1 && !maze[r][c + 1]) q.push({ it.first + 1, {r,c + 1} });
    if (r > 0 && !maze[r - 1][c]) q.push({ it.first + 1, {r - 1,c} });
    if (r < R - 1 && !maze[r + 1][c]) q.push({ it.first + 1, {r + 1,c} });
  }

  cout << -1;

  return 0;
}