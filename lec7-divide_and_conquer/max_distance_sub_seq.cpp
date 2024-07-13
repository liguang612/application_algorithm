#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int* arr, C, N, T;

bool check(int d) {
  int cnt = 1, end = arr[0];
  for (int i = 1; i < N; i++)
    if (arr[i] - end >= d) {
      end = arr[i];
      cnt++;

      if (cnt == C) break;
    }

  return cnt == C;
}

int exec() {
  // Init
  int tmp;
  for (int i = 0; i < N; i++) cin >> arr[i];
  sort(arr, arr + N);

  // Process
  int low = 1, high = arr[N - 1] - arr[0], mid;
  while (low != high)
  {
    mid = (low + high + 1) / 2;
    if (check(mid)) low = mid;
    else high = mid - 1;

    // cout << low << ' ' << high << ' ' << mid << endl;
  }

  return low;
}

int main() {
  // freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> T;
  for (int i = 0; i < T; i++)
  {
    cin >> N >> C;
    arr = new int[N];
    cout << exec() << endl;
  }

  return 0;
}