#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int res = 0;
map<char, int> last;
string p, t;

void initLast() {
  int sz = p.length();
  for (int i = 0; i < sz; i++)
    last[p[i]] = i;
}

int main() {
  // freopen("input.txt", "r", stdin);/

  getline(cin, p);
  getline(cin, t);

  initLast();

  int lenP = p.length(), sz = t.length() - p.length();

  for (int i = 0; i <= sz;)
  {
    int j;
    for (j = lenP - 1; j >= 0; j--)
      if (p[j] != t[i + j])
      {
        i += max(j - last[t[i + j]], 1);
        break;
      }

    if (j == -1) {
      i++;
      res++;
    };
  }

  cout << res;

  return 0;
}