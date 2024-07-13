#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001], N;

int maxFromLeft(int L, int R) {
  int m = -1000000000, s = 0;

  for (int i = L; i <= R; i++)
  {
    s += arr[i];
    m = max(m, s);
  }

  return m;
}

int maxFromRight(int L, int R) {
  int m = -1000000000, s = 0;

  for (int i = R; i >= L; i--)
  {
    s += arr[i];
    m = max(m, s);
  }

  return m;
}

int exec(int L, int R) {
  if (L == R) return arr[L];

  int delegate1 = exec(L, (L + R) / 2), delegate2 = exec((L + R) / 2 + 1, R), delegate3 = maxFromRight(L, (L + R) / 2) + maxFromLeft((L + R) / 2 + 1, R);

  return max(max(delegate1, delegate2), delegate3);
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> arr[i];
  }

  cout << exec(0, N - 1);

  return 0;
}