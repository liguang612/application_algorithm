#include <iostream>
#include <vector>

using namespace std;

vector<int> edges[100001];
int N, M, cur = 0, articulationPoints = 0, bridges = 0;
int low[100001], num[100001];
bool visited[100001], isArticulation[100001];

void dfs(int v, int pv) {
    visited[v] = true;
    low[v] = num[v] = cur++;
    int children = 0;

    for (int u : edges[v]) {
        if (u == pv) continue;

        if (visited[u]) {
            low[v] = min(low[v], num[u]);
        }
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] >= num[v] && pv != -1) {
                isArticulation[v] = true;
            }
            if (low[u] > num[v]) {
                bridges++;
            }
            children++;
        }
    }
    if (pv == -1 && children > 1) {
        isArticulation[v] = true;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        low[i] = num[i] = -1;
        visited[i] = false;
        isArticulation[i] = false;
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (isArticulation[i]) {
            articulationPoints++;
        }
    }

    cout << articulationPoints << " " << bridges << endl;
    return 0;
}
