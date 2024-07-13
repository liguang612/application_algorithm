#include <iostream>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

bool onStack[100001];
int cnt, cur_num, e, low[100001], n, num[100001];
set<int> graph[100001];
stack<int> S;

void analyze(int v, int prev) {
  low[v] = num[v] = ++cur_num;
  S.push(v);
  onStack[v] = true;

  for (auto u : graph[v])
  {
    if (u == prev) continue;
    if (!num[u]) {
      analyze(u, v);
      low[v] = min(low[u], low[v]);
    }
    else if (onStack[u]) low[v] = min(low[v], num[u]);
  }

  if (low[v] == num[v])
  {
    cnt++;

    int u;
    do
    {
      u = S.top();
      S.pop();
      onStack[u] = false;
    } while (u != v);
  }
}

int main() {
  freopen("input.txt", "r", stdin);

  cin >> n >> e;

  int a, b;
  for (int i = 1; i <= e; i++)
  {
    cin >> a >> b;
    graph[a].insert(b);
  }

  for (int i = 1; i <= n; i++)
    if (!num[i]) analyze(i, 0);

  // // for (int i = 1; i <= n; i++)
  //   cout << num[i] << ' ' << low[i] << endl;

  cout << cnt;

  return 0;
}