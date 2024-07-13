#include <iostream>
#include <cmath>
#include <vector> 

using namespace std;

int arr[1000000], n;
vector<int> dict[20];

void preprocessing() {
  for (int i = 0; i < n; i++)
  {
    dict[0].push_back(i);
  }

  int delta = 1;
  for (int i = 1; i <= log2(n); i++)
  {
    int sz = dict[i - 1].size() - delta;
    for (int j = 0; j < sz; j++)
    {
      if (arr[dict[i - 1][j]] < arr[dict[i - 1][j + delta]])
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

  if (arr[dict[delta][a]] < arr[dict[delta][b - pow(2, delta) + 1]])
  {
    return dict[delta][a];
  }
  else {
    return dict[delta][b - pow(2, delta) + 1];
  }
}

int main() {
  freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  preprocessing();

  int a, b, m, _sum = 0;
  cin >> m;

  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;

    _sum += process(a, b);
  }

  cout << _sum;

  return 0;
}