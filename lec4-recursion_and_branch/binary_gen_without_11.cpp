#include <iostream>
#include <string>

using namespace std;

int N;

void gen(string res) {
  if (res.length() == N)
  {
    cout << res << endl;
    return;
  }
  gen(res + "0");
  if (res[res.length() - 1] == '0' || res.empty()) gen(res + "1");
}

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> N;

  gen("");

  return 0;
}