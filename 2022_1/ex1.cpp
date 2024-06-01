#include <iostream>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);

    int cnt = 0, k, m, n, arr[100001];

    cin >> n >> k >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int s = 0;
    for (int i = 0; i < k; i++)
    {
        s += arr[i];
    }

    if (s == m)
    {
        cnt++;
    }
    for (int i = k; i < n; i++)
    {
        s += arr[i] - arr[i - k];
        if (s == m)
        {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}