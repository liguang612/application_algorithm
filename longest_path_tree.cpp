#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[1000001];
bool visited[1000001];
int N;

pair<int, int> bfs(int start) {
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;

    q.push({ start, 0 });
    visited[start] = true;

    pair<int, int> farthest = { start, 0 };

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;

        q.pop();

        for (auto edge : tree[node]) {
            if (!visited[edge.first]) {
                visited[edge.first] = true;
                q.push({ edge.first, dist + edge.second });
                if (dist + edge.second > farthest.second) {
                    farthest = { edge.first, dist + edge.second };
                }
            }
        }
    }

    return farthest;
}

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int u, v, w;
    for (int i = 1; i < N; i++) {
        cin >> u >> v >> w;
        tree[u].push_back({ v, w });
        tree[v].push_back({ u, w });
    }

    pair<int, int> t1 = bfs(1); // Bắt đầu BFS từ nút bất kỳ, ở đây là nút 1
    pair<int, int> t2 = bfs(t1.first); // BFS lần thứ hai từ nút xa nhất tìm được

    cout << t1.first << ' ' << t1.second << endl;

    cout << t2.second; // In ra độ dài đường đi dài nhất

    return 0;
}
