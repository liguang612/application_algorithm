#include <iostream>

using namespace std;

int m, n, arr[10000], cnt = 0, sum = 0;

void solve(int k)
{
    if (k == n)
    {
        if (sum == m)
        {
            cnt++;
        }
        return;
    }
    int sz = (m - sum) / arr[k];
    for (int i = 1; i <= sz; i++)
    {
        sum += arr[k] * i;
        solve(k + 1);
        sum -= arr[k] * i;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(0);

    cout << cnt << endl;

    return 0;
}