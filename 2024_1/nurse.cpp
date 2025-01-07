#include <iostream>
#include <algorithm>

using namespace std;

int n, k1, k2, dp[1001][2];

int main()
{
    cin >> n >> k1 >> k2;

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = 0;
    }
    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1];

        int lwr = max(0, i - k2), upr = i - k1;
        for (int j = lwr; j <= upr; j++)
        {
            dp[i][1] = (dp[i][1] + dp[j][0]) % 1000000007;
        }
    }

    cout << (dp[n][0] + dp[n][1]) % 1000000007 << endl;

    return 0;
}