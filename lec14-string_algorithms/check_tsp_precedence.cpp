#include <iostream>
#include <vector>

using namespace std;

int c[1001][1001], inlet[1001], n, s;
vector<int> graph[1001];
vector<int> route;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;

  int a, b, tmp;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    route.push_back(tmp);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> c[i][j];

  cin >> tmp;
  for (int i = 0; i < tmp; i++)
  {
    cin >> a >> b;
    graph[a].push_back(b);
    inlet[b]++;
  }

  tmp = route[0];
  for (int v : route)
  {
    if (!inlet[v])
    {
      s += c[tmp][v];
      for (int j : graph[v])
      {
        inlet[j]--;
      }
      tmp = v;
    }
    else {
      s = -1;
      goto endfor;
    }
  }
  s += c[tmp][route[0]];

endfor:
  cout << s;

  return 0;
}