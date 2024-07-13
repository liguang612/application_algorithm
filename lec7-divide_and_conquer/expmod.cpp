#include <iostream>
#define Q 1000000007

using namespace std;

unsigned long long int a, b, k, r;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> a >> b;

  a %= Q;
  while (b >= Q)
  {
    k = b / Q;
    b = b % Q + k;
  }

  unsigned long long res = 1;
  for (int i = 0; i < b; i++)
  {
    res *= a;
    res %= Q;
  }

  cout << res;

  return 0;
}