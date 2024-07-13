#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);

  int count = 0, n, q, tmp;
  vector<int> v;
  vector<int>::iterator it1, it2;

  cin >> n >> q;
  for (int i = 0; i < n; i++)
  {
    cin >> tmp;
    v.push_back(tmp);
  }

  sort(it1 = v.begin(), it2 = v.end());

  it2--;
  while (it1 != it2)
  {
    if (*it1 + *it2 > q)
    {
      it2--;
    }
    else if (*it1 + *it2 < q)
    {
      it1++;
    }
    else {
      count++;
      it1++;
    }
  }

  cout << count;

  return 0;
}