#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct segment {
  int head;
  int tail;

  bool operator<(segment other) {
    return tail < other.tail;
  }
} segment;

int n, rec[100001];
segment arr[100001];
vector<int> pack;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i].head >> arr[i].tail;
  }
  sort(arr, arr + n);

  pack.push_back(arr[0].tail);

  for (int i = 1; i < n; i++)
  {
    if (arr[i].head > *(pack.end() - 1)) pack.push_back(arr[i].tail);
  }

  cout << pack.size();

  return 0;
}