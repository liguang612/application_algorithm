#include <iostream>

using namespace std;

int arr[1000001], m, n, record = -1000000000;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;

  cin >> arr[0];
  record = max(record, m = arr[0]);

  for (int i = 1; i < n; i++)
  {
    cin >> arr[i];
    record = max(record, m = max(arr[i], arr[i] + m));
  }

  cout << record;

  return 0;
}