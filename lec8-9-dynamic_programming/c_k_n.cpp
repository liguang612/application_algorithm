#include <iostream>

using namespace std;

int main() {
  long long k, n, res[1000];

  cin >> k >> n;

  for (int i = 0; i <= n; i++) {
    res[i] = 1;
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = i - 1; j > 0; j--) res[j] = (res[j - 1] + res[j]) % 1000000007;
  }

  cout << res[k];

  return 0;
}