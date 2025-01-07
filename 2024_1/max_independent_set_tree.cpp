#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
vector<int> tree[MAXN + 1];
int weights[MAXN + 1];
long long dp[MAXN + 1][2];

void dfs(int v, int parent)
{
    dp[v][0] = 0;
    dp[v][1] = weights[v];
    for (int u : tree[v])
    {
        if (u == parent)
            continue;
        dfs(u, v);
        dp[v][0] += max(dp[u][0], dp[u][1]);
        dp[v][1] += dp[u][0];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << endl;

    return 0;
}
