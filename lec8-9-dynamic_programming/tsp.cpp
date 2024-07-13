#include <iostream>

using namespace std;

int c[21][21], ** mem, n;

int tsp(int i, int S) {
  if (mem[i][S]) return mem[i][S];
  if (S == (1 << n) - 1) return mem[i][S] = c[i][0];

  int res = 1000000000;
  for (int j = 0; j < n; j++)
  {
    if (S & (1 << j)) continue;
    res = min(res, c[i][j] + tsp(j, S | (1 << j)));
  }

  return mem[i][S] = res;
}

int main() {
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> c[i][j];

  mem = new int* [n];
  for (int i = 0; i < n; i++)
    mem[i] = new int[1 << n];

  cout << tsp(0, 1);

  return 0;
}