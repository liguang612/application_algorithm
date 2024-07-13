#include <iostream>

using namespace std;

int main() {
  unsigned long long a, b;
  unsigned long long a1, a2, b1, b2, c1, c2;

  cin >> a >> b;

  a1 = a / 10; b1 = b / 10;
  a2 = a % 10; b2 = b % 10;

  c1 = a1 + b1 + (a2 + b2) / 10;
  c2 = (a2 + b2) % 10;

  if (c1 > 0)
  {
    cout << c1 << c2;
  }
  else {
    cout << c2;
  }


  return 0;
}