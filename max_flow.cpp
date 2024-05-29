#include <iostream>
#include <queue>
#include <vector>
#include <climits> // Để sử dụng INT_MAX

using namespace std;

int n, m, s, t, res = INT_MAX, in[10001], out[10001];
vector<pair<int, int>> edges[10001];

int main() {
    freopen("input.txt", "r", stdin);

    int outlet = 0;
    queue<int> q;

    cin >> n >> m >> s >> t;

    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;

        edges[a].push_back({ b, c });
        in[b] += c;
    }

    // Khởi tạo hàng đợi với nguồn
    q.push(s);
    for (auto i : edges[s])
    {
        outlet += i.first;
        in[i.first] -= i.second;
    }


    while (!q.empty()) {
        int tmp = q.front();
        q.pop();

        cout << tmp << endl;

        // Duyệt các con của tmp
        for (auto& edge : edges[tmp]) {
            int v = edge.first;
            int capacity = edge.second;

            if (!in[v]) {
                q.push(v);
                in[v] -= capacity;
                outlet += capacity;

                // Cập nhật luồng ngược trên các cạnh ngược lại
                for (auto& reverse_edge : edges[v]) {
                    int u = reverse_edge.first;
                    int reverse_capacity = reverse_edge.second;
                    in[u] -= reverse_capacity;
                    outlet += reverse_capacity;
                }

                // Xóa cạnh
                edge.second = 0;
            }
        }
    }

    cout << outlet;

    return 0;
}
