#include <iostream>
#include <set>

using namespace std;

bool* visited;
int e, v;
set<int>* graph;

void dfs(int v) {
  cout << v << ' ';
  visited[v] = true;

  for (auto _v : graph[v])
  {
    if (!visited[_v]) dfs(_v);
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> v >> e;
  graph = new set<int>[v + 1];
  visited = new bool[v + 1];

  int a, b;
  for (int i = 1; i <= e; i++)
  {
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
    visited[i] = false;
  }

  for (int i = 1; i <= v; i++)
  {
    if (!visited[i]) dfs(i);
  }

  return 0;
}