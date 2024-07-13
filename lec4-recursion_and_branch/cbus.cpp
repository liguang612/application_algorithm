#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[23];
int c_min = 1000000000, cost = 0, dist[23][23], K, m = 1000000000, N;
vector<int> route;

bool check(int idx, int cnt) {
  if (idx <= N && !K) return false; // Hết chỗ thì cook
  if (visited[idx]) return false; // Thăm rồi thì cook
  if (idx > N && !visited[idx - N]) return false; // Chưa đón thì trả cđj?
  if (cost + dist[*(route.end() - 1)][idx] + (2 * N - cnt) * c_min > m) return false; // Đi lối này thì không có tương lai

  return true;
}

void attempt(int count) {
  if (count == 2 * N)
  {
    m = min(m, cost + dist[*(route.end() - 1)][0]);
    return;
  }

  for (int i = 1; i <= 2 * N; i++)
  {
    if (check(i, count))
    {
      cost += dist[*(route.end() - 1)][i];
      route.push_back(i);
      visited[i] = true;
      if (i <= N) K--; else K++;

      attempt(count + 1);

      // Khôi phục
      visited[i] = false;
      route.pop_back();
      cost -= dist[*(route.end() - 1)][i];
      if (i <= N) K++; else K--;
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> N >> K;
  for (int i = 0; i <= 2 * N; i++)
    for (int j = 0; j <= 2 * N; j++)
    {
      cin >> dist[i][j];
      if (dist[i][j] && dist[i][j] < c_min) c_min = dist[i][j];
    }

  route.push_back(0);
  attempt(0);

  cout << m;

  return 0;
}