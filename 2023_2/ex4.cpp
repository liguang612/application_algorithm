#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // freopen("input.txt", "r", stdin);

    bool visited[1001];
    int n, k, ** arr;

    cin >> n >> k;

    arr = new int* [n + 1];
    for (int i = 0; i <= n; i++) {
        arr[i] = new int[n + 1];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0, cur[101];
    vector<int> route[101];

    for (int i = 1; i <= k; i++) {
        route[i].push_back(0);
    }
    visited[0] = true;
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }

    cnt = 1;
    while (cnt < n) {
        for (int i = 1; i <= k; i++) {
            int _min = 100000000, _j = 0;

            for (int j = 1; j <= n; j++) {
                if (!visited[j] && arr[cur[i]][j] < _min) {
                    _min = arr[cur[i]][j];
                    _j = j;
                }
            }

            if (_j) {
                route[i].push_back(_j);
                visited[_j] = true;
                cur[i] = _j;
                cnt++;
            }
        }
    }

    cout << k << endl;
    for (int i = 1; i <= k; i++) {
        cout << route[i].size() << endl;
        for (int j : route[i]) cout << j << ' ';

        cout << endl;
    }

    return 0;
}
