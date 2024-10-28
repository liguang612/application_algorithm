#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> combination;

void display()
{
  for (int i : combination)
    cout << i << ' ';
  cout << endl;
}

void attempt()
{
  if (combination.size() == k)
  {
    display();
    return;
  }

  for (int i = *(combination.end() - 1) + 1; i <= n; i++)
  {
    combination.push_back(i);
    attempt();
    combination.pop_back();
  }
}

int main()
{
  // freopen("input.txt", "r", stdin);

  cin >> k >> n;

  int sz = n - k + 1;
  for (int i = 1; i <= sz; i++)
  {
    combination.push_back(i);
    attempt();
    combination.pop_back();
  }

  return 0;
}