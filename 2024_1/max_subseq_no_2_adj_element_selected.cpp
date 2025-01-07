#include <iostream>

using namespace std;

int n, arr[100001], dp[100001][2];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + arr[i];
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

    return 0;
}