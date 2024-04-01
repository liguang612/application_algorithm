#include <iostream>

using namespace std;

int *a, m, n, res = 0;

void attempt(int k) {
    if (k == n && m == 0)
    {
        ++res;
        return;
    }

    int tmp = m / a[k];

    for (int i = 1; i <= tmp; i++)
    {
        m -= a[k] * i;
        attempt(k + 1);

        // Restore
        m += a[k] * i;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> n >> m;
    a = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    attempt(0);

    cout << res;

    return 0;
}