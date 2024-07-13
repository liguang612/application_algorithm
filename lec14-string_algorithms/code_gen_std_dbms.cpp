#include <iostream>
#include <string>

using namespace std;

int L, n;

string gen_form() {
  string str = "";
  for (int i = 0; i < L; i++)
    str += "0";

  return str;
}

int main() {
  // freopen("input.txt", "r", stdin);

  int k;
  string res;

  cin >> n >> L;
  for (int i = 0; i < n; i++)
  {
    cin >> k;

    res = gen_form();
    auto it = res.end(); it--;

    while (k)
    {
      *it = (k % 10 + 48);
      k /= 10;
      it--;
    }

    cout << res << endl;
  }

  return 0;
}