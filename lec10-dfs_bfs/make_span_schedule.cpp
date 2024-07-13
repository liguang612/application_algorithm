#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

bool appended[10001];
int cost = 0, d[10001], inlet[10001], m, n;
set<int> graph[10001];
vector<int> q;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> d[i];

  int a, b;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    graph[a].insert(b);
    inlet[b]++;
  }

  for (int i = 1; i <= n; i++)
    if (!inlet[i]) {
      q.push_back(i);
      appended[i] = true;
    };

  while (!q.empty()) {
    // Do the task
    int _min = 1000000000;
    for (int i : q) _min = min(_min, d[i]);

    cost += _min;

    for (auto i = q.begin(); i != q.end();)
    {
      d[*i] -= _min;

      // Complete the task
      if (!d[*i])
      {
        for (int j : graph[*i]) inlet[j]--;
        i = q.erase(i);
      }
      else
        i++;
    }

    // Plan the task to do
    for (int i = 1; i <= n; i++)
      if (!inlet[i] && d[i] && !appended[i]) {
        q.push_back(i);
        appended[i] = true;
      }
  }

  cout << cost;

  return 0;
}