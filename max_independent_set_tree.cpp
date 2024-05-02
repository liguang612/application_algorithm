#include<iostream>
#include <vector>

using namespace std;

const int N = 100001;
vector<int> link[N];
int dp[N][2], u, v, w[N];

void dfs(int u, int p) {
    dp[u][0] = 0;
    dp[u][1] = w[u];

    for (int v : link[u]) {
        if (v == p) continue;

        dfs(v, u);

        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    };

    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        link[u].push_back(v);
        link[v].push_back(u);
    }

    dfs(1, 0);
    
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    return 0;
}
