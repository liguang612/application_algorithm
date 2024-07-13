#include <iostream>
#include <vector>

using namespace std;

bool conflict[25][25], visited[25];
int cnt, L, M, n1, n2, P, l, r;
vector<int> invested;

bool check(int v) {
  if (visited[v]) return false;
  if (v <= n1 && l == M) return false;
  if (v > n1 && r == M) return false;
  for (int i : invested)
    if (conflict[i][v]) return false;

  return true;
}

void attempt() {
  if (invested.size() <= L && l && r) cnt++;
  if (invested.size() == L) return;

  int lwr = invested.empty() ? 1 : *(invested.end() - 1) + 1;
  for (int i = lwr; i <= n1 + n2; i++)
    if (check(i))
    {
      invested.push_back(i);
      if (i <= n1) l++; else r++;
      visited[i] = true;

      attempt();

      invested.pop_back();
      if (i <= n1) l--; else r--;
      visited[i] = false;
    }
}

int main() {
  freopen("input.txt", "r", stdin);

  cin >> n1 >> n2 >> L >> M >> P;

  int a, b;
  for (int i = 0; i < P; i++)
  {
    cin >> a >> b;
    conflict[a][b] = conflict[b][a] = true;
  }

  attempt();

  cout << cnt;

  return 0;
}