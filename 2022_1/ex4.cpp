#include <iostream>
#include <algorithm>

using namespace std;

int n, a[100001], f[100001][2], res = 0;

int main() {
    freopen("input.txt", "r", stdin);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i][0] = max(f[i - 1][0], f[i - 1][1]);
        f[i][1] = f[i - 1][0] + a[i];

        int tmp = max(f[i][0], f[i][1]);
        res = max(res, tmp);
    }

    cout << res;

    return 0;
}