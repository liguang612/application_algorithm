#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool visited[16];
int d[16], N, Q = 15;
vector<int> timetable;

void attempt(int k) {
  if (k > N)
  {
    Q = min(Q, (int)timetable.size());
    return;
  }
  for (int i = 0; i < N; i++)
  {
    if (visited[i]) continue;

    int tmp = d[i];

    visited[i] = true;
    for (int j = 0; j < timetable.size(); j++)
    {
      if (timetable[j] + tmp <= 6)
      {
        timetable[j] += tmp;

        attempt(k + 1);

        timetable[j] -= tmp;
      }
    }
    if (timetable.size() < Q)
    {
      timetable.push_back(tmp);
      attempt(k + 1);
      timetable.pop_back();
    }
    visited[i] = false;
  }
}

int main() {
  freopen("input.txt", "r", stdin);

  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> d[i];

  attempt(1);

  cout << Q;

  return 0;
}