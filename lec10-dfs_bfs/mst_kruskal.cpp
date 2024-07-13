#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool visited[100001];
int cnt = 0, M, N, pi[100001], s = 0;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> graph;

pair<int, int> find(int x) {
  int rank = 0;
  while (x != pi[x]) {
    x = pi[x];
    rank++;
  }
  return { x,rank };
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N >> M;

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
    auto ra = find(a), rb = find(b);
    if (ra.first != rb.first) {
      s += c;
      ++cnt;

      if (ra.second > rb.second) pi[rb.first] = ra.first;
      else pi[ra.first] = rb.first;
    }

    if (cnt == N - 1) break;
  }

  cout << s;

  return 0;
}