#include <iostream>
#include <algorithm>

using namespace std;

typedef struct job {
  int deadline;
  int profit;

  bool operator< (job other) {
    return profit > other.profit ? true : profit < other.profit ? false : deadline < other.deadline;
  }
} job;

int n, plan[100001], sum = 0;
job* jobs;

int main() {
  // freopen("input.txt", "r", stdin);

  cin >> n;

  jobs = new job[n];
  for (int i = 0; i < n; i++)
  {
    cin >> jobs[i].deadline >> jobs[i].profit;
  }

  sort(jobs, jobs + n);

  for (int i = 0; i < n; i++)
  {
    for (int j = jobs[i].deadline - 1; j >= 0; j--)
    {
      if (!plan[j])
      {
        plan[j] = jobs[i].deadline;
        sum += jobs[i].profit;

        break;
      }
    }
  }

  cout << sum;

  return 0;
}