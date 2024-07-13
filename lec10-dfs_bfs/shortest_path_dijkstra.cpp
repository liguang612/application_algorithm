#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

bool founded[100001];
unsigned int cost[100001], e, s, t, v;
map<int, int> graph[100001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
  freopen("input.txt", "r", stdin);

  cin >> v >> e;
  for (int i = 1; i <= v; i++)
    cost[i] = -1;

  int a, b, c;
  for (int i = 0; i < e; i++)
  {
    cin >> a >> b >> c;
    graph[a][b] = c;
  }

  cin >> s >> t;

  cost[s] = 0;
  pq.push({ 0,s });
  while (!pq.empty())
  {
    int u = pq.top().second;
    pq.pop();

    for (auto e : graph[u])
      if (!founded[e.first])
        if (cost[u] + e.second < cost[e.first])
        {
          cost[e.first] = cost[u] + e.second;
          pq.push({ cost[e.first], e.first });
        }
  }

  cout << (cost[t] == (unsigned int)-1 ? -1 : cost[t]);

  return 0;
}