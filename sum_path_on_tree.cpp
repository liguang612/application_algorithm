#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> g[MAXN];
int dp[MAXN], sz[MAXN], ans[MAXN], n;

void dfs1(int node, int par) {
    sz[node] = 1;
    for (auto& child : g[node]) {
        if (child.first != par) {
            cout << child.first << ' ';
            dfs1(child.first, node);
            cout << endl;
            sz[node] += sz[child.first];
            dp[node] += dp[child.first] + sz[child.first] * child.second;
        }
    }
}

void dfs2(int node, int par) {
    ans[node] = dp[node];
    for (auto& child : g[node]) {
        if (child.first != par) {
            dp[node] -= dp[child.first] + sz[child.first] * child.second;
            sz[node] -= sz[child.first];
            dp[child.first] += dp[node] + sz[node] * child.second;
            sz[child.first] += sz[node];

            dfs2(child.first, node);

            dp[child.first] -= dp[node] + sz[node] * child.second;
            sz[child.first] -= sz[node];
            dp[node] += dp[child.first] + sz[child.first] * child.second;
            sz[node] += sz[child.first];
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }

    dfs1(1, 0);

    for (int i = 1; i <= n; i++)
    {
        cout << dp[i] << ' ';
    }
    cout << endl;

    dfs2(1, 0);

    int max_value = *max_element(ans + 1, ans + n + 1);
    cout << max_value << endl;

    return 0;
}
