#include <iostream>
#include <set>

using namespace std;

int visited[100001];
int e, n;
set<int>* graph;

bool dfs(int v, int s) {
  visited[v] = s;

  for (int e : graph[v])
    if (visited[e] == s) return false;
    else if (!visited[e] && !dfs(e, 2 - s + 1)) return false;

  return true;
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n >> e;
  graph = new set<int>[n + 1];

  int a, b;
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b;
    graph[a].insert(b);
    graph[b].insert(a);
  }

  cout << dfs(1, 1);

  return 0;
}