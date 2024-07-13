#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool* visited;
int n, rec, x;
set<pair<int, int>>* graph;

void dfs(int s, int dist) {
  bool isLeaf = visited[s] = true;

  for (pair<int, int> e : graph[s])
  {
    if (!visited[e.first])
    {
      isLeaf = false;
      dfs(e.first, dist + e.second);
    }
  }

  if (isLeaf && dist > rec)
  {
    rec = dist;
    x = s;
  }
}

void resetState() {
  for (int i = 0; i <= n; i++) visited[i] = false;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  graph = new set<pair<int, int>>[n + 1];
  visited = new bool[n + 1];
  resetState();

  int a, b, c;
  for (int i = 1; i < n; i++)
  {
    cin >> a >> b >> c;
    graph[a].insert({ b,c });
    graph[b].insert({ a,c });
  }

  // Find x
  dfs(1, 0);

  rec = 0;
  resetState();

  // Find max weight x -> y
  dfs(x, 0);

  cout << rec;

  return 0;
}