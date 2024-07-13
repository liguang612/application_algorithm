#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[301];
int cnt = 0, D, K, M, N, d[301], pi[301];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> graph;
vector<pair<int,int>> res;

pair<int, int> find(int x) {
  int rank = 0;
  while (x != pi[x]) {
    x = pi[x];
    rank++;
  }
  return { x,rank };
}

int main() {
  freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M >> D >> K;

  int a, b, c;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b >> c;
    graph.push({ c,{a,b} });
  }

  for (int i = 1; i <= N; i++) pi[i] = i;

  while (!graph.empty() && cnt < N - 1)
  {
    auto e = graph.top();
    graph.pop();

    a = e.second.first; b = e.second.second; c = e.first;

    if (d[a] == D || d[b] == D) continue; // Nếu đã đạt bậc D thì cook

    auto ra = find(a), rb = find(b);
    if (ra.first != rb.first) {
      ++cnt;
      ++d[a]; ++d[b];
      res.push_back(e.second);

      if (ra.second > rb.second) pi[rb.first] = ra.first;
      else pi[ra.first] = rb.first;
    }

    if (cnt == K) break;
  }

  cout << K << endl;
  for (auto i : res) {
    cout << i.first << ' ' << i.second << endl;
  }

  return 0;
}
