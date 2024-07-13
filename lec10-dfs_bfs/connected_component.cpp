#include <iostream>
#include <set>

using namespace std;

bool* visited;
int e, v, cnt;
set<int>* graph;

void dfs(int v) {
  visited[v] = true;

  for (auto _v : graph[v])
    if (!visited[_v]) dfs(_v);
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> v >> e;
  graph = new set<int>[v + 1];
  visited = new bool[v + 1];

  for (int i = 1; i <= v; i++) visited[i] = false;

  int a, b;
  for (int i = 1; i <= e; i++)
  {
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }

  for (int i = 1; i <= v; i++)
  {
    if (!visited[i]) {
      ++cnt;
      dfs(i);
    };
  }

  cout << cnt;

  return 0;
}