// Xuất phát từ 0, đón khách ở [1..n], trả khách ở i + n
// Không được phép có quá k khách cùng 1 thời điểm, mỗi khách không được ngồi trên xe quá D km.
// c[i][j]: khoảng cách từ i -> j
// Tìm giá trị của path ngắn nhất.

#include <iostream>
#include <vector>

using namespace std;

bool visited[23];
int c[23][23], cmin = 1000000000, cost = 0, d[12], D, K, N, m = 1000000000;
vector<int> route;

bool check(int v, int k) {
    if (visited[v]) return false;
    if (v <= N && !K) return false;
    if (v > N && !visited[v - N]) return false;
    if (cost + (2 * N + 1 - k) * cmin > m) return false;
    for (int i = 1; i <= N; i++)
        if (d[i] && d[i] + c[*(route.end() - 1)][v] > D) return false;

    return true;
}

void attempt(int k) {
    if (k > 2 * N) {
        m = min(m, cost + c[*(route.end() - 1)][0]);
        return;
    }
    for (int i = 1; i <= 2 * N; i++)
    {
        if (check(i, k)) {
            int tmp = c[*(route.end() - 1)][i];

            cost += tmp;
            if (i <= N) K--; else K++;
            route.push_back(i);
            visited[i] = true;
            for (int i = 1; i <= N; i++)
                if (d[i]) d[i] += tmp;

            attempt(k + 1);

            cost -= tmp;
            if (i <= N) K++; else K--;
            route.pop_back();
            visited[i] = false;
            for (int i = 1; i <= N; i++)
                if (d[i]) d[i] -= tmp;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> K >> D;
    for (int i = 0; i <= 2 * N; i++)
        for (int j = 0; j <= 2 * N; j++)
        {
            cin >> c[i][j];
            if (i != j) cmin = min(cmin, c[i][j]);
        }

    route.push_back(0);
    visited[0] = true;

    attempt(1);

    cout << m;

    return 0;
}