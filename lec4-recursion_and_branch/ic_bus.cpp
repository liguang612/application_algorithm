#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int c[5001], s[5001], d[5001], m, n;
vector<int> tree[5001];

int bfs(int root) {
  int lv = 0;
  queue<int> q;
  vector<int> next;

  q.push(root);

  while (lv < d[root])
  {
    int f = q.front();
    q.pop();

    for (auto i : tree[f])
    {
      q.push(i);
      if (s[i] > s[root] + c[root])
      {
        next.push_back(i);
        s[i] = s[root] + c[root];
      }
    }
    ++lv;
  }

  for (auto& i : next)
  {
    bfs(i);
  }

}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n >> m;

  for (int i = 1; i <= n; i++)
  {
    cin >> c[i] >> d[i];
  }

  int a, b;
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  fill(s, s + n + 1, 1000000000);
  s[1] = 0;

  bfs(1);

  cout << s[n];


  return 0;
}
