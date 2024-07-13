#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

template <typename T> inline void read(T& x)
{
  x = 0;
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c))
  {
    x = x * 10 + c - 48;
    c = getchar();
  }
}

int arr[1000003], n;
vector<int> dict[20];

void preprocessing() {
  for (int i = 0; i < n; i++)
  {
    dict[0].push_back(arr[i]);
  }

  int delta = 1, sz = log2(n);
  for (int i = 1; i <= sz; i++)
  {
    int sz = dict[i - 1].size() - delta;
    for (int j = 0; j < sz; j++)
    {
      if (dict[i - 1][j] < dict[i - 1][j + delta])
      {
        dict[i].push_back(dict[i - 1][j]);
      }
      else {
        dict[i].push_back(dict[i - 1][j + delta]);
      }
    }
    delta *= 2;
  }
}

int process(int a, int b) {
  int delta = log2(b - a + 1);

  if (dict[delta][a] < dict[delta][b - (1 << delta) + 1])
  {
    return dict[delta][a];
  }
  else {
    return dict[delta][b - (1 << delta) + 1];
  }
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  read(n);
  for (int i = 0; i < n; i++)
  {
    read(arr[i]);
  }

  preprocessing();

  int a, b, m, _sum = 0;
  read(m);

  for (int i = 0; i < m; i++)
  {
    read(a);
    read(b);

    _sum += process(a, b);
  }

  cout << _sum;

  return 0;
}