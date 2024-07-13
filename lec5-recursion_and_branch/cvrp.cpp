#include <iostream>
#include <algorithm>

using namespace std;

bool visited[13];
int c_min = 1000000000, cost, d[13], dist[13][13], K, load[6], m = 1000000000, n, nbr, Q, segments, x[14], y[6];

bool checkX(int v, int k) {
  if (v > 0 && visited[v]) return false;
  if (load[k] + d[v] > Q) return false;

  return true;
}

void attemptX(int s, int k) {
  if (!s)
  {
    if (k < K) attemptX(y[k + 1], k + 1);
    return;
  }
  for (int v = 0; v <= n; v++)
  {
    if (checkX(v, k))
    {
      cost += dist[s][v];
      load[k] += d[v];
      ++segments;
      visited[v] = true;
      x[s] = v;

      // Execute
      if (v)
      {
        if ((n + nbr - segments) * c_min < m) attemptX(v, k);
      }
      else {
        if (k == K)
        {
          if (segments == n + nbr) m = min(m, cost);
        }
        else
          if ((cost + (n + nbr - segments) * c_min) < m) attemptX(y[k + 1], k + 1);
      }

      // Restore
      cost -= dist[s][v];
      load[k] -= d[v];
      --segments;
      visited[v] = false;
    }
  }
}

bool checkY(int v, int k) {
  if (!v) return true;
  if (load[k] + d[v] > Q) return false;
  if (visited[v]) return false;

  return true;
}

void attemptY(int k) {
  for (int v = y[k - 1] ? y[k - 1] + 1 : 0; v <= n; v++)
  {
    if (checkY(v, k))
    {
      y[k] = v;
      if (v)
      {
        cost += dist[0][v];
        load[k] += d[v];
        ++segments;
        visited[v] = true;
      }

      // Execute
      if (k < K) attemptY(k + 1);
      else { nbr = segments; attemptX(y[1], 1); }

      if (v)
      {
        // Restore
        cost -= dist[0][v];
        load[k] -= d[v];
        --segments;
        visited[v] = false;
      }
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> K >> Q;
  for (int i = 1; i <= n; i++)
  {
    cin >> d[i];
  }

  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      cin >> dist[i][j];
      if (dist[i][j]) c_min = min(c_min, dist[i][j]);
    }
  }

  attemptY(1);

  cout << m;

  return 0;
}