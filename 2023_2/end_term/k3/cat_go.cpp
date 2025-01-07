#include <iostream>
#include <algorithm>

using namespace std;

int n, p[1001], dp[1001] = {0};

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], dp[j] + p[i - j]);

    cout << dp[n];

    return 0;
}