#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int d[100001], f[100001], N[100001], n, p[100001];
set<pair<int, int>>* graph;

void dfs1(int u) {
  for (auto e : graph[u])
    if (!p[e.first])
    {
      p[e.first] = u;

      dfs1(e.first); // DFS to update d[v] & N[v]

      // Now, let's update d[u] & N[u]
      d[u] += d[e.first] + N[e.first] * e.second;
      N[u] += N[e.first];
    }
}

void phase1() {
  for (int i = 1; i <= n; i++)
  {
    p[i] = d[i] = f[i] = 0;
    N[i] = 1;
  }
  p[1] = 1;
  dfs1(1);
}

void dfs2(int u) {
  for (auto i : graph[u])
    if (!p[i.first])
    {
      p[i.first] = u;

      int F = f[u] - (d[i.first] + N[i.first] * i.second);
      f[i.first] = F + d[i.first] + i.second * (n - N[i.first]);

      dfs2(i.first);
    }
}

void phase2() {
  for (int i = 1; i <= n; i++) p[i] = 0;
  f[1] = d[1];
  p[1] = 1;
  dfs2(1);
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;
  graph = new set<pair<int, int>>[n + 1];

  int a, b, c;
  for (int i = 1; i < n; i++)
  {
    cin >> a >> b >> c;
    graph[a].insert({ b,c });
    graph[b].insert({ a,c });
  }

  phase1();
  phase2();

  cout << *max_element(f + 1, f + n + 1);

  return 0;
}