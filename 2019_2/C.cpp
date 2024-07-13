#include <iostream>
#include <string>

using namespace std;

int N;
string dp[200][100001], name;

int main() {
  freopen("input.txt", "r", stdin);

  cin >> name >> N;

  int sz = name.size();
  for (int i = 0; i <= N; i++)
    dp[i][0] = "";
  fill(dp[0], dp[0] + sz + 1, "");
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= sz; j++)
    {
      string s1 = dp[i - 1][j - 1] + name[j], s2 = dp[i][j - 1];
      dp[i][j] = s1 < s2 ? s2 : s1;
    }

  cout << dp[N][sz];

  return 0;
}