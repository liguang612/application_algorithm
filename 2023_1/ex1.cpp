#include <iostream>
#include <algorithm>

using namespace std;

bool exist[100001] = {};
int arr[2001] = {}, cnt = 0, n;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    exist[arr[i]] = true;
  }

  sort(arr, arr + n);
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++) {
        if (arr[i]+arr[j] > arr[n-1]) break;
        else if (exist[arr[i]+arr[j]]) cnt++;
    }
  }

  cout << cnt;

  return 0;
}
