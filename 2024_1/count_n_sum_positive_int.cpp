#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main()
{
    int n, dp[51] = {0};
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i / 2; j++)
        {
            dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }

    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }

    return 0;
}
