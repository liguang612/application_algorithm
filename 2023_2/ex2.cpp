// Xuất phát từ 0, đón khách ở [1..n], trả khách ở i + n
// Không được phép có quá k khách cùng 1 thời điểm, mỗi khách không được ngồi trên xe quá D km.
// c[i][j]: khoảng cách từ i -> j
// Tìm giá trị của path ngắn nhất.

#include <iostream>
#include <vector>

using namespace std;

int n, k, D, c[24][24], seat[12], res = 1000000000;

void attempt(vector<int> customers, int cnt, int cur, int path) {
    // BOundary
    if (path > res) {
        return;
    }

    if (cnt == n) {
        path += c[cur][0];
        res = path < res ? path : res;
    }

    // Grab
    if (customers.size() < k) {
        for (int i = 1; i <= n; i++) {
            if (!seat[i] && path + c[cur][i] < res) {
                bool ok = true;

                // Check if seat longer than D or not
                for (int j : customers) {
                    if (seat[j] + c[cur][j] >= D) {
                        ok = false;
                        break;
                    }
                }

                if (ok) {
                    for (int j : customers) {
                        seat[j] += c[cur][j];
                    }
                    customers.push_back(i);
                    attempt(customers, cnt, i, path + c[cur][i]);

                    // Restore
                    for (int j : customers) {
                        seat[j] -= c[cur][j];
                    }
                    customers.pop_back();
                }
            }
        }
    }
    // Drop
    for (auto it = customers.begin(); it != customers.end(); it++) {
        if (path + c[cur][*it + n] < res) {
            bool ok = true;
            int tmp = *it;

            for (int i : customers) {
                if (seat[i] + c[cur][*it + n] >= D) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                for (int j : customers) {
                    seat[j] += c[cur][*it + n];
                }
                customers.erase(it);
                attempt(customers, cnt + 1, *it + n, path + c[cur][*it + n]);

                // Restore
                for (int j : customers) {
                    seat[j] -= c[cur][*it + n];
                }
                customers.insert(it, tmp);
            }
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n >> k >> D;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * n + 1;j++) {
            cin >> c[i][j];
        }
    }

    vector<int> customers;

    attempt(customers, 0, 0, 0);
    cout << res;

    return 0;
}

