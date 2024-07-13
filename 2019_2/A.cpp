#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int m, n;

bool check(int k) {
  int s = k * k;

  if (k % 2) {
    int less = (s - 1) / 2, more = less + 1;
    int l = min(m, n), mo = max(m, n);
    return less <= l && more <= mo;
  }
  else {
    return s / 2 <= min(m, n);
  }
}

int main() {
  cin >> m >> n;

  int p = (int)sqrt(m + n);
  for (int i = p; i >= 0; i--)
  {
    if (check(i)) { cout << i; break; }
  }

  return 0;
}