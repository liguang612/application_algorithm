#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[23];
unsigned int c[23][23], cmin = -1, cost = 0, n, rec = -1;
vector<int> route;

bool check(int v, int cnt) {
  if (visited[v]) return false;
  if (cost + c[*(route.end() - 1)][v] + cmin * (2 * n - 2 * cnt) > rec) return false;

  return true;
}

void attempt(int k) {
  if (k == n)
  {
    rec = min(rec, cost + c[*(route.end() - 1)][0]);
    return;
  }

  for (int i = 1; i <= n; i++)
  {
    if (check(i, k))
    {
      cost += c[*(route.end() - 1)][i] + c[i][i + n];
      route.push_back(i);
      route.push_back(i + n);
      visited[i] = true;

      attempt(k + 1);

      visited[i] = false;
      route.pop_back();
      route.pop_back();
      cost -= c[*(route.end() - 1)][i] + c[i][i + n];
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i <= 2 * n; i++)
    for (int j = 0; j <= 2 * n; j++)
    {
      cin >> c[i][j];
      if (c[i][j]) cmin = min(cmin, c[i][j]);
    }

  route.push_back(0);
  attempt(0);

  cout << rec;

  return 0;
}